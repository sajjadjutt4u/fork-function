#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>

static int *grandSum;

void main(){
	int sum = 0, arr[1000], start = 0, end = 100;
	int fd1[2], fd2[2];
	pipe(fd1);
	pipe(fd2);

	grandSum = mmap(NULL, sizeof *grandSum, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

	*grandSum = 0;
	
	for(int i = 0; i < 1000; i++)
		arr[i] = 1;

	if(fork() == 0){
		start = 0;
		end = 100;

		for(int i = start; i < end; i++)
			sum += arr[i];
		
		//close(fd1[0]);
		//write(fd1[1], sum, sizeof(int));
		//close(fd1[1]);		

		//wait(NULL);
		
		//close(fd2[1]);
		//read(fd2[0], sum, sizeof(int));
		*grandSum += sum;
		//close(fd2[0]);		

		printf("process id %d  and sum is %d \n",getpid(), *grandSum);
		sum = 0; // reseting sum value
	} 
	else if(fork() == 0){
		start = 100;
		end = 200;
		
		for(int i = start; i < end; i++)
			sum += arr[i];
		
		//close(fd1[0]);
		//write(fd1[1], sum, sizeof(int));
		//close(fd1[1]);		

		//wait(NULL);
		
		//close(fd2[1]);
		//read(fd2[0], sum, sizeof(int));
		*grandSum += sum;
		//close(fd2[0]);		

		printf("process id %d  and sum is %d \n",getpid(), *grandSum);
		sum = 0; // reseting sum value
	} 
	else if(fork() == 0){
		start = 200;
		end = 300;
		
		for(int i = start; i < end; i++)
			sum += arr[i];
		
		//close(fd1[0]);
		//write(fd1[1], sum, sizeof(int));
		//close(fd1[1]);		

		//wait(NULL);
		
		//close(fd2[1]);
		//read(fd2[0], sum, sizeof(int));
		*grandSum += sum;
		//close(fd2[0]);		

		printf("process id %d  and sum is %d \n",getpid(), *grandSum);
		sum = 0; // reseting sum value
	} 
	else if(fork() == 0){
		start = 300;
		end = 400;
		
		for(int i = start; i < end; i++)
			sum += arr[i];
		
		//close(fd1[0]);
		//write(fd1[1], sum, sizeof(int));
		//close(fd1[1]);		

		//wait(NULL);
		
		//close(fd2[1]);
		//read(fd2[0], sum, sizeof(int));
		*grandSum += sum;
		//close(fd2[0]);		
		printf("process id %d  and sum is %d \n",getpid(), *grandSum);
		
		sum = 0; // reseting sum value
	}
	else if(fork() == 0){
		start = 400;
		end = 500;
		
		for(int i = start; i < end; i++)
			sum += arr[i];
		
		//close(fd1[0]);
		//write(fd1[1], sum, sizeof(int));
		//close(fd1[1]);		

		//wait(NULL);
		
		//close(fd2[1]);
		//read(fd2[0], sum, sizeof(int));
		*grandSum += sum;
		//close(fd2[0]);		

		printf("process id %d  and sum is %d \n",getpid(), *grandSum);
		sum = 0; // reseting sum value
	} 
	else if(fork() == 0){
		start = 500;
		end = 600;
		
		for(int i = start; i < end; i++)
			sum += arr[i];
		
		//close(fd1[0]);
		//write(fd1[1], sum, sizeof(int));
		//close(fd1[1]);		

		//wait(NULL);
		
		//close(fd2[1]);
		//read(fd2[0], sum, sizeof(int));
		*grandSum += sum;
		//close(fd2[0]);		

		printf("process id %d  and sum is %d \n",getpid(), *grandSum);
		sum = 0; // reseting sum value
	} 
	else if(fork() == 0){
		start = 600;
		end = 700;
		
		for(int i = start; i < end; i++)
			sum += arr[i];
		
		//close(fd1[0]);
		//write(fd1[1], sum, sizeof(int));
		//close(fd1[1]);		

		//wait(NULL);
		
		//close(fd2[1]);
		//read(fd2[0], sum, sizeof(int));
		*grandSum += sum;
		//close(fd2[0]);		

		printf("process id %d  and sum is %d \n",getpid(), *grandSum);
		sum = 0; // reseting sum value
	} 
	else if(fork() == 0){
		start = 700;
		end = 800;
		
		for(int i = start; i < end; i++)
			sum += arr[i];
		
		//close(fd1[0]);
		//write(fd1[1], sum, sizeof(int));
		//close(fd1[1]);		

		//wait(NULL);
		
		//close(fd2[1]);
		//read(fd2[0], sum, sizeof(int));
		*grandSum += sum;
		//close(fd2[0]);		

		printf("process id %d  and sum is %d \n",getpid(), *grandSum);
		sum = 0; // reseting sum value
	} 
	else if(fork() == 0){
		start = 800;
		end = 900;
		
		for(int i = start; i < end; i++)
			sum += arr[i];
		
		//close(fd1[0]);
		//write(fd1[1], sum, sizeof(int));
		//close(fd1[1]);		

		//wait(NULL);
		
		//close(fd2[1]);
		//read(fd2[0], sum, sizeof(int));
		*grandSum += sum;
		//close(fd2[0]);		

		printf("process id %d  and sum is %d \n",getpid(), *grandSum);
		sum = 0; // reseting sum value
	} 
	else{
		start = 900;
		end = 1000;
		
		for(int i = start; i < end; i++)
			sum += arr[i];
		
		//close(fd1[0]);
		//write(fd1[1], sum, sizeof(int));
		//close(fd1[1]);		

		//wait(NULL);
		
		//close(fd2[1]);
		//read(fd2[0], sum, sizeof(int));
		*grandSum += sum;
		//close(fd2[0]);		

		printf("process id %d  and sum is %d \n",getpid(), *grandSum);
		sum = 0; // reseting sum value
		
		//wait(NULL);
		//printf("process id %d  and sum is %d \n",getpid(),grandSum);
	} 

	//return 0;
}
