#include <stdio.h>
#include <mpi.h>
#include <stdio.h>
#define N 100
#define FROM_MASTER 1
#define FROM_WORKER 2 

int main(int argc, char *argv[]){

	int tasikd,numtasks,numworkers,rows;
	double a[N][N], b[N][N], c[N][N];
	MPI_Status status;
	MPI_Init(&argc, &argv);
	
	//get the rank
	//GROUP OF PROCESSES IN THE PROGRAM
	MPI_Comm_rank(MPI_COMM_WORLD,&taskid);
	
	//get the total processes
	MPI_Comm_size(MPI_COMM_WORLD,&numtasks);
	
	numworkers=numtasks-1;
	
	//divide length of array by #nro of processes
	
	//n->length of matrix
	rows=N / numworkers; //calculate rows for each process to compute 
	if(taskid==0){
	//prepare data
	//preparing data→ initialize matrix a , b, do computation and send results back k
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				a[i][j]=i+j;
				b[i][j]=i*j;
				}
			}
			//send the matrix to the worker processes
			for(int dest=1; dest < numworkers; dest++){
				MPI_Send(&a[(dest-1)*rows][0]*N,MPI_DOUBLE,dest,FROM_MASTER,MPI_COMM_WORLD);
				MPI_Send(&b,N*N,MPI_DOUBLE,dest,FROM_MASTER,MPI_COMM_WORLD);}
				}
				
				
				//receive rthe result from workers processes
				for(in source=1;source<numworkers;source++){
					MPI_Recv(&c[(source-1)*rows][0],rows*N,MPI_DOUBLE,source,FROM_WORKER,MPI_COMM_WORLD,&status);
				
				}
				
					//print the result
					for(int i=0;i<N;i++){
						for(int j=0;j<N;j++){
							printf("6.2%f, c[i][j]);
							
							}
							}
							
							}
				if(taskid>0){
				
				
				//receive matrix data
				MPI_Recv(&a,rows*N, MPI_DOUBLE, 0, FROM_MASTER, MPI_COMM_WORLD,&status);
				MPI_Recv(&B,N*N,MPI_DOUBLE,0,FROM_MASTER,MPI_COMM_WORLD,&status);
				
				//Perform matrix multiplication
				for(int i=0;i<rows;i++){
					for(int j=0;j<N;j++){
						for(int k=0;k<N;k++){
							c[i][k]=a[i][j] * b[j][k];
							
							}
							
							}
							
							}
							
							//send the result back to root
							MPI_Send(&c,rows*N,MPI_DOUBLE,0,FROM_WORKER,MPI_COMM_WORLD);
							}
							
			
	
	MPI_Finalize();
	