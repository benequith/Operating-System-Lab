#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int  counter = 0;

void *func(void *arg){
   pthread_t *thd_id = (pthread_t*)arg; 
   pthread_t sid;
   
   //pthread_mutex_lock( &mutex1 );
	sid = pthread_self();
	printf("Hello from new thread %lu got %lu!\n",sid,*thd_id); 
	counter++;
	printf("Counter value: %d\n",counter);
   //pthread_mutex_unlock( &mutex1 );
   
   pthread_exit(NULL); 
}

int main(){
   int rc1, rc2;
   pthread_t tid1, tid2, sid;

   /* Create independent threads each of which will execute func*/

   if( (rc1=pthread_create( &tid1, NULL, &func, (void *)&tid1)))
   {
      printf("Thread creation failed: %d\n", rc1);
	  exit (1);
   }

   if( (rc2=pthread_create( &tid2, NULL, &func, (void *)&tid2)))
   {
      printf("Thread creation failed: %d\n", rc2);
	  exit (1);
   }

   /* Wait till threads are complete before main continues. Unless we  */
   /* wait we run the risk of executing an exit which will terminate   */
   /* the process and all threads before the threads have completed.   */

   pthread_join( tid1, NULL);
   pthread_join( tid2, NULL); 

   return 0;
}