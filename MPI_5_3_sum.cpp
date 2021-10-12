#include <mpi.h> 
#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int np, pid;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	int partial_sum = 0;
	if (pid == 0)
	{
		int a[] = { 1, 2, 3, 4, 5 };
		for (int i = 0; i < 5; i++)
			partial_sum += a[i];
	}
	else if (pid == 1)
	{
		int a[] = { 6, 7, 8, 9, 10 };
		for (int i = 0; i < 5; i++)
			partial_sum += a[i];
	}
	int sum;
	//  MPI_Reduce(partial data,reduction buffer,count,datatype,MPI_Operation,root,communicator)
		MPI_Reduce(&partial_sum, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	if (pid == 0)
	{
		printf("Sum of array is : %d\n", sum);
	}
	MPI_Finalize();
	return 0;
}
