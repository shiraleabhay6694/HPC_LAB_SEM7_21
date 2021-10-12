#include<iostream>
#include<mpi.h>
using namespace std;
int main(int argc, char* argv[]) {
	int rank;
	int size = 10000;
	int num_procs = 0;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int i;
	
	char input_buffer[80000];
	char recv_buffer[80000];
	srand(time(NULL));
	for (i = 0; i < size; i++) {
		input_buffer[i] = rand() % 256;
	}
	int j;
	for (j = 1; j < num_procs; j++)
	{
		int k = 0;
		for (i = j * size; i < j * size + size; i++)

		{
			input_buffer[i] = input_buffer[k];
			k++;
		}
	}
	double total_time = 0.0;  double start_time = 0.0;
	for (i = 0; i < 100; i++)
	{
		MPI_Barrier(MPI_COMM_WORLD);
		start_time = MPI_Wtime();
		MPI_Alltoall(input_buffer, size, MPI_CHAR, recv_buffer, size, MPI_CHAR, MPI_COMM_WORLD);
		MPI_Barrier(MPI_COMM_WORLD);    total_time += (MPI_Wtime() - start_time);
	}
	if (rank == 0)
	{
		printf("Average time for alltoall %d: %f secs\n", size, total_time / 100);
	}
	MPI_Finalize();

	return 0;
}