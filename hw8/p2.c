#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



void *computation (void *id){
    int *arr
        long *myid = args-> id;
        long id;
        long nthreads;
        return NULL;
}
int main(int argc, char *argv[]){
        int myid, numprocs;
        long double PI = 3.14159265358979323846264338327950288419716939937510;
        long double pi, sum, partial_sum, x;
        int nthreads;
        pthread_t *thread_arr;
        long *thread_ids;
        //read number of threads from command line
        if (argc !=2) {
                fprintf(stderr, "usage: %s <n>\n", argv[0]);
                fprintf(stderr, "where <n> is the number of threads\n");
        return 1;
    }
        //convert given parameter into number base 10
        nthreads = strtol(argv[1], NULL, 10);

        thread_arr = malloc(sizeof(pthread_t)*nthreads);
        thread_ids = (long*)malloc(sizeof(long)*nthreads);

        //create thread
        for (int i=0; i<nthreads;i++){
                thread_ids[i]=i;
                pthread_create(&thread_arr[i],NULL,computation,(void*)&thread_ids[i]);

        }
        partial_sum=0.0;
        for(i=nthreads/numprocs*myid+1; i<= nthreads/numprocs*(myid+1); i++) {
        x = ((double)i - 0.5)/nthreads;
        partial_sum+= 4.0 / (1.0 + x*x);
    }
        //JOIN THRE THREADS

        for(int i=0;i<nthreads;i++){
                pthread_join(thread_arr[i],NULL);
        }





}
