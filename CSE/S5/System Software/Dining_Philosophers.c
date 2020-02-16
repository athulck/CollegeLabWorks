
#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/mman.h>
#include <sys/stat.h>

#include <unistd.h>



sem_t chopstick[5];
pthread_t philosopher[5];

void * eat(int *arg)
{
	int i = arg[0];
	int n = arg[1];

	sem_wait(&chopstick[i]);
	sem_wait(&chopstick[(i+1)%n]);
	
	printf("\nPhilosopher %d is now eating ... ", i);

	sem_post(&chopstick[(i+1)%n]);
	sem_post(&chopstick[i]);

	printf("\nPhilosopher %d is now thinking ... ", i);
}


void main()
{
	int n;
	printf("\nEnter the number of philosophers : ");
	scanf("%d",&n);

	// Initializing the semaphores
	for(int i=0; i<n; i++)
	{
		printf("\nPhilosopher %d is now thinking ... ", i);
		sem_init(&chopstick[i], 0, 1);
	}

	int arg[2];

	for(int i=0; i<n; i++)
	{
		arg[0] = i;
		arg[1] = n;
		pthread_create(&philosopher[i], NULL, (void *)eat, (void *)&arg);
		sleep(1);
	}

	while(1)
	{
		for(int i=0; i<n; i++)
		{
			pthread_join(philosopher[i], NULL);
			sleep(1);
		}
	}

}