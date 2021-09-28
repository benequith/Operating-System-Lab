/* creation of a process with fork()  
Understand parallel execution of parent & child*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h> 

void forkexample() { 
    pid_t pid;
	printf("Before fork \n");
	printf("pid = %d, process_id = %d, parent_process_id = %d, \n\n", pid, getpid(), getppid());
	
	pid = fork(); // replicates current process
	printf("After fork \n");
	
	if ( pid == 0) {// child process because return value zero 
		printf("Hello from Child!\n"); 
		printf("fork = %d, process_id = %d, parent_process_id = %d, \n", pid, getpid(), getppid());
	}
	
    else if (pid > 0) {// parent process because return value non-zero and not -1. 
    	printf("Hello from Parent!\n"); 
		printf("fork = %d, process_id = %d, parent_process_id = %d, \n", pid, getpid(), getppid());
    }
    
	else // return value negative
	printf("fork failed");
} 


int main() 
{ 
    forkexample(); 
    return 0; 
} 
