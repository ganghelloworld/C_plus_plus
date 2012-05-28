#ifndef __DNS_H_
#define __DNS_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <pthread.h>

#include "thread_pool.h"

#define SERV_PORT   53
#define LISTENQ     12

#define DNSLEN      1024
#define DOMAINLEN   64 * 4
#define FILTER_DOMAIN_LIST "./filter_domain.list"

struct dns_para{
	int fd;
	char buf[DNSLEN];
	struct sockaddr_in addr;
};


void my_err(const char * err_string, int line);
int look_up(char* recv_buf, int len, char* lookup_buf);
void get_domain_name(char* buf, char* dn);
int main_loop();
void * response(void *);

#endif
