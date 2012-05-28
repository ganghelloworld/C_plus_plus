#ifndef __THREADPOOL_H_
#define __THREADPOOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include <pthread.h>
#include <signal.h>
//#include "dns.h"
typedef struct worker
{
	void *arg;
	struct worker *next;
}thread_worker;

typedef struct
{
	pthread_mutex_t queue_lock;
	pthread_cond_t queue_ready;

	thread_worker *queue_head;

	int shutdown;
	pthread_t *thread_id;
	int max_thread_num;
	int cur_queue_size;
}thread_pool;

typedef void (*sighandler_t)(int);

int pool_add_worker(void *arg);
void * thread_routine(void *arg);
void pool_init(int max_thread_num);
void pool_destroy_sig(int);
int pool_destroy();
#endif
