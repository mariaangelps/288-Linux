#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#define PI 3.14159265358979323846264338327950288419716939937510

//global variables
pthread_mutex_t lock;
long double partial_sum;
int numterms;
int nthreads;
long double total_sum = 0.0L; 
void*computation (void *id){
        long *myid = (long *) id;
        //partial_sum=0.0;
        long double partial_sum = 0.0L;

        //for(int i=nthreads/numterms*myid+1; i<= nthreads/numterms*(myid+1); i++) {
        
        int chunk = numterms / nthreads;

        long long start = (*myid) * chunk + 1;

        long long end = (*myid + 1) * chunk;

        for (long long i = start; i <= end; i++) {
           long double x = ((long double)i - 0.5L) / numterms;
           partial_sum += 4.0L / (1.0L + x * x);
}



  pthread_mutex_lock(&lock);
        total_sum+=partial_sum;
  pthread_mutex_unlock(&lock);




 return NULL;
}

int main(int argc, char *argv[]){
        int myid;
        //long double *partial_sum, x;
        //int nthreads;
        pthread_t *thread_arr;
        long *thread_ids;
        //read number of threads from command line
        if (argc !=3) {
                fprintf(stderr, "usage: %s <n>\n", argv[0]);
                fprintf(stderr, "where <n> is the number of threads\n");
        return 1;
    }
        //convert given parameter into number base 10
        nthreads = strtol(argv[2], NULL, 10);
        numterms = strtol(argv[1], NULL,10);
        thread_arr = malloc(sizeof(pthread_t)*nthreads);
        thread_ids = (long*)malloc(sizeof(long)*nthreads);

        //create thread
        for (int i=0; i<nthreads;i++){
                thread_ids[i]=i;
                pthread_create(&thread_arr[i],NULL,computation,(void*)&thread_ids[i]);

        }

        //JOIN THRE THREADS

        for(int i=0;i<nthreads;i++){
                pthread_join(thread_arr[i],NULL);
        }


        long double pi_estimate = total_sum / numterms;
        printf("Estimated value of pi: %.22Lf\n", pi_estimate);
        printf("Error: %.22Lf\n", fabsl(pi_estimate - PI));

}