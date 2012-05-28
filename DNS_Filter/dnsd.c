#include "dns.h"
#include "thread_pool.h"

#define THREAD_NUM 5

int main()
{


	printf("Start\n");
	pool_init(THREAD_NUM);
	printf("Thread Pool Init Over\n");

	printf("Start access DNS request\n");
	main_loop();

	return 0;
}
