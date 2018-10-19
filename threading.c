#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int arr[1000];

void fillArray(){
	for(int i = 0; i < 1000; i++)
		arr[i] = i;
}

void * TestThread(void *arg)
{
	int start = (int)arg;
	start = start + 10;
	return ((void*)start);
}

void * sumValues(void *arg)
{
	int sum = 0;
	int start = (int)arg;
	int end = start + 100;
	
	for(int i = start; i < end; i++)
		sum += i;

	return ((void*)sum);
}

int main ()
{
	int sum = 0;

	// Entering data into the array
	fillArray();
	
	// Making array of status to store all threads infomation
	int status_t[10];

	// Making an array of threads
	pthread_t thread_t[10];

	// Creating 10 threads
	for(int i = 0; i < 10; i++){
		pthread_create(&thread_t[i],NULL,sumValues,(void*)(i*100));
		//printf("\nSum returned By Thread {%d} %d\n", i, status_t[i]);

	}
	
	// Joining 10 threads
	for(int i =0; i < 10; i++)	
		pthread_join(thread_t[i],(void**) & status_t[i]);
	
	// Adding all values
	for(int i = 0; i < 10; i++)
		sum += status_t[i];

	printf("\nSum returned By All Threads %d\n", sum);

	return 0;
}
