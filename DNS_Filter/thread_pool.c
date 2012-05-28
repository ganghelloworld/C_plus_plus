#include "thread_pool.h"
thread_pool *pool = NULL;

void pool_init(int max_thread_num)
{
	int i = 0;
	signal(SIGINT, pool_destroy_sig);
	pool = (thread_pool *)malloc(sizeof(thread_pool));

	pthread_mutex_init(&(pool->queue_lock), NULL);
	pthread_cond_init(&(pool->queue_ready), NULL);

	pool->queue_head = NULL;

	pool->max_thread_num = max_thread_num;
	pool->cur_queue_size = 0;
	pool->shutdown = 0;

	pool->thread_id = (pthread_t *)malloc(max_thread_num * sizeof(pthread_t));

	for(i = 0; i < max_thread_num; i++)
	{
			pthread_create(&(pool->thread_id[i]), NULL, thread_routine, NULL);
	}
}
int pool_add_worker(void *arg)
{
		thread_worker * new_worker = (thread_worker *)malloc(sizeof(thread_worker));
		new_worker->arg = arg;
		new_worker->next = NULL;

		pthread_mutex_lock(&(pool->queue_lock));
		thread_worker * temp = pool->queue_head;
		if(temp != NULL)
		{
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new_worker;
		}
		else
		{
			pool->queue_head = new_worker;	
		}
		assert(pool->queue_head != NULL);
		pool->cur_queue_size++;
		pthread_cond_signal(&(pool->queue_ready));
		pthread_mutex_unlock(&(pool->queue_lock));
		return 0;
}
void * thread_routine(void* arg)
{
	while(1)
	{
		pthread_mutex_lock(&(pool->queue_lock));
		while(pool->cur_queue_size == 0 && !pool->shutdown)
		{
			pthread_cond_wait(&(pool->queue_ready), &(pool->queue_lock));
		}
		if(pool->shutdown)
		{
			pthread_mutex_unlock(&(pool->queue_lock));
			pthread_exit(NULL);
		}

		assert(pool->cur_queue_size != 0);
		assert(pool->queue_head != NULL);

		pool->cur_queue_size --;
		thread_worker * worker = pool->queue_head;
		pool->queue_head = worker->next;
		pthread_mutex_unlock(&(pool->queue_lock));

		printf("Response request\n");
		response(worker->arg);
		free(worker);
		worker = NULL;
	}
	pthred_exit(NULL);
}
void  pool_destroy_sig(int signum)
{
	printf("Caught signal %d\tPool Destoried\n", signum);
	pool_destroy();
	exit(signum);
}
int pool_destroy()
{
	int i = 0;
	if(pool->shutdown)
	{
			return -1;
	}
	pool->shutdown = 1;
	pthread_cond_broadcast(&(pool->queue_ready));
	for(i = 0; i < pool->max_thread_num; i++)
	{
		pthread_join(pool->thread_id[i], NULL);
	}
	free(pool->thread_id);
	thread_worker * head = NULL;
	while(pool->queue_head != NULL)
	{
		head = pool->queue_head;
		pool->queue_head = pool->queue_head->next;
		free(head);
	}
	pthread_mutex_destroy(&(pool->queue_lock));
	pthread_cond_destroy(&(pool->queue_ready));
	free(pool);
	pool = NULL;
	return 0;
}
