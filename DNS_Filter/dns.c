#include "dns.h"

int main_loop()
{
	int sock_fd;
	int optval;
	int ret;
	int i, j;
	pid_t pid;
	socklen_t cli_len;
	struct sockaddr_in cli_addr, serv_addr;
	char recv_buf[DNSLEN];

	sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock_fd < 0)
	{
		my_err("socket", __LINE__);
	}
	optval = 1;
	if(setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, (void *)&optval, sizeof(int)) < 0)
	{
		my_err("setsockopt", __LINE__);
	}

	memset(&serv_addr, 0, sizeof(struct sockaddr_in));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERV_PORT);
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(sock_fd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr_in)) < 0)
	{
		my_err("bind", __LINE__);
	}

	cli_len = sizeof(struct sockaddr_in);
	pthread_mutex_t lock;
	pthread_mutex_init(&lock, NULL);
	for(j = 1;;j++)
	{
		pthread_mutex_lock(&lock);
		struct dns_para *dp;
		dp = (struct dns_para *)malloc(sizeof(struct dns_para));
		dp->fd = sock_fd;
		ret = recvfrom(sock_fd, recv_buf, sizeof(recv_buf), 0, (struct sockaddr*)&cli_addr, &cli_len);
		if(ret < 0)
		{
			my_err("accept", __LINE__);
		}
		recv_buf[ret] = '\0';
		memcpy(dp->buf, recv_buf, sizeof(recv_buf));
		memcpy(&(dp->addr), &cli_addr, cli_len);
		//pthread_t pth;
		//pthread_create(&pth, NULL, response, (void *)dp);
		printf("Add on request to worker queue\n");
		pool_add_worker((void *)dp);
		pthread_mutex_unlock(&lock);
		//pthread_join(pth, NULL);
	}
	return 0;
}
static int accept_num = 0;
void* response(void * vdp)
{
	char lookup_buf[DNSLEN], domain_name[DOMAINLEN];
	struct dns_para *dp = (struct dns_para*)vdp;
	printf("Thread id is 0x%x\n", pthread_self());
	printf("Accept num %d\t client, ip: %s\n", accept_num++ , inet_ntoa(dp->addr.sin_addr));

	get_domain_name(dp->buf, domain_name);	
	if(filter_domain(domain_name) == 1)
	{
		printf("%s is forbidden\n", domain_name);
		return NULL;
	}
	printf("Domain Name : %s\n", domain_name);
	int lookup_len = look_up(dp->buf, sizeof(dp->buf), lookup_buf);
	sendto(dp->fd, lookup_buf, lookup_len, 0, (struct sockaddr*)&(dp->addr), sizeof(struct sockaddr_in));
	//free(vdp);
	return 0;
}
int look_up(char* recv_buf, int len, char* lookup_buf)
{
	int sock_fd;
	int ret, i, serv_len;
	struct sockaddr_in serv_addr;
	sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock_fd < 0)
	{
		my_err("socket", __LINE__);
	}
	memset(&serv_addr, 0, sizeof(struct sockaddr_in));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, "202.118.224.100",&serv_addr.sin_addr);
	sendto(sock_fd, recv_buf, len, 0, (struct sockaddr*)&serv_addr, sizeof(struct sockaddr));
	ret = recvfrom(sock_fd, lookup_buf, DNSLEN, 0, (struct sockaddr*)&serv_addr, &serv_len);
	close(sock_fd);
	return ret;
}
int filter_domain(char * domain_name)
{
	int domain_fd;
	ssize_t count;
	char get_domain[DOMAINLEN];
	char ch[1];
	int j = 0;
	domain_fd = open(FILTER_DOMAIN_LIST, O_RDONLY);
	if(domain_fd < 0)
	{
		my_err("Open Domain Filter", __LINE__);
		return 0;
	}
	while((count = read(domain_fd, ch, 1)) == 1)
	{
		if(*ch == '\n')
		{
			get_domain[j] = '\0';
			if(strcmp(get_domain, domain_name) == 0) return 1;
			j = 0;
			sleep(1);
		}
		else
		{
			get_domain[j++] = *ch;
		}
	}
	return 0;
}
void my_err(const char * err_string, int line)
{
	fprintf(stderr, "line:%d ", line);
	perror(err_string);
	exit(1);
}
void get_domain_name(char* buf, char* domain_name)
{
	int i = 0,  j = 0, node_len;
	char * p;
	p = buf + 12;
	while(*p != '\0')
	{
		node_len = (int)*p;
		p++;
		while(node_len--)
		{
			domain_name[j++] = *p;
			p++;
		}
		domain_name[j++] = '.';
	}
	domain_name[j-1] = '\0';
}
