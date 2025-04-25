#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	int rank;
	 //Start the MPI environment
	 MPI_Init(&argc, &argv);
	 
	 
	 
	 //Each process is identified by it's rank
	 //To get the rank of each process, we use
	 // MPI_Comm_rank(MPI_COMM_WORLD);
	  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	  

	 //MPI_COMM_WORLD basically refers to the group of processes
	 //within the program
	 
	 
	 //To get total number/size of processes
	 MPI_Comm_size(MPI_COMM_WORLD,&size);
	 
	 printf("Im process %d of total %d", rank, size);

	 
	 
	 //Exit the MPI Environment
	 MPI_Finalize();
}