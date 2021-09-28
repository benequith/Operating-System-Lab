#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h> 

int globalvble = 10; 

int main() {
   	pid_t returnval;   
	int localvble = 20; 
	int childretval; // from child process: user provided return value   
	int exitstatus, i=0;  // parent process : child's exit status   

	if ((returnval=vfork()) >= 0) {    // including actions to be performed by both parent and child processes      
	if (returnval == 0) { // inside child        
		printf("CHILD:: fork() returnValue = %d, My PID = %d, my Parent's ID = %d\n",returnval,getpid(), getppid());        //globalvble++; localvble++;    
		while (i < 10) { 
			printf("CHILD:: i = %d, local vble = %d, global vble = %d\n\n",i,localvble,globalvble);
			++localvble; ++globalvble;   
			++i;        
		}
//		system("ps afxj");
       	printf("CHILD:: Enter an exit value (0 to 255) \n"); 
		scanf("%d", &childretval); 
		printf("CHILD:: Good Bye\n\n"); 
		//exit(0); 
		exit(childretval);      
	}
	else if (returnval > 0) { // inside parent  
		sleep(2);   
		printf("PARENT:: My PID = %d, my Child's PID = %d, my parent's PID = %d \n",getpid(), returnval, getppid());
       	printf("PARENT:: i = %d, local vble = %d, global vble = %d\n\n",i,localvble,globalvble);
       	while (i < 10) {
			printf("PARENT:: local vble = %d, global vble = %d\n\n",localvble,globalvble);  
			++localvble; ++globalvble;
			++i;        
		}   
		wait(&exitstatus);  
		printf("PARENT:: Child's exit code is -> %d \n",WEXITSTATUS(exitstatus));
		printf("PARENT:: Good Bye\n\n");       
		exit(0); // parent process is terminating -- normally    
	}      
	} // outer-if complete....   
	else { 
		printf ("Child creation error...."); 
		exit(0); 
	}
}
