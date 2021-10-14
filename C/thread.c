
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *func(void *arg)
{
	printf("Rodando thread...\n");
	
	//waste computation
	volatile unsigned int i;
	for(i = 0; i < 4000000000; i++);
	
	printf("Finaliza thread...\n");
	pthread_exit(NULL);
}

int main(void)
{
	pthread_t threadID1, threadID2;
	
	//Create new thread
	pthread_create(&threadID1, NULL, &func, NULL);
	pthread_create(&threadID2, NULL, &func, NULL);
	
	printf("Rodando main...\n");
	
	//Waste computation
	volatile unsigned int i;
	for(i = 0; i < 3000000000; i++);
	
	printf("Finaliza main...\n");
	
	pthread_join(threadID1, NULL);
	pthread_join(threadID2, NULL);

	return 0;
}
