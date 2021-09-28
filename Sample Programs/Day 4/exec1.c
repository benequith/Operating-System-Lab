#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <string.h>

int main(){  
	pid_t pid;
	char *args[3], a[3];
	int l, i;
	char *x;
	
	if ((pid = fork()) == 0) { // child process
      system ("echo CHILD executing LS:");
	  printf("\nI am Child, my ID %d, MY PARENT ID = %d",getpid(),getppid());
	  printf("\n");
      execlp("ls", "ls", "-l", (char*)NULL);
      exit(0);
    } 
   
    else if (pid > 0) { // parent process
      wait(NULL);
	  system ("echo PARENT executing User Input Command:");
	  printf("\n\nI am Parent, my ID %d, I have child with ID: %d, My ParentID = %d", getpid(), pid, getppid());
	  
	  printf ("\nEnter the command: ");
	  scanf("%s", a);
	  l = strlen(a);
      x = (char *)malloc(l + 1);
      strcpy(x, a);
      args[0] = x;

	  printf ("\nEnter the argument for %s: ", args[0]);
	  scanf("%s", a);
	  l = strlen(a);
      x = (char *)malloc(l + 1);
      strcpy(x, a);
      args[1] = x;	

	  args[2] = NULL;
	  
	  execvp(args[0], args);      
	  exit(0);
}
   
   else printf("Problem in child creation....\n");
   return 0;
}