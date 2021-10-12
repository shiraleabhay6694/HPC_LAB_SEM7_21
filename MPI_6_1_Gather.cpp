#include<iostream>
#include<mpi.h>
using namespace std;
int main(int argv, char* argc[]) {
	int rank = 0;
	int data = 0;
	int partner_rank = 0;
	int size = 0;
	int* buffer = NULL;
	MPI_Init(&argv, &argc);


	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	partner_rank = rank + 1;
	if (rank == 0) {
		buffer = (int*)malloc(sizeof(int) * size);
	}
	// MPI_Gather(send_buffer,send_count,send_datatype,recv_buffer_data,recv_count,recv_datatype,root,communicator);
	MPI_Gather(&partner_rank, 1, MPI_INT, buffer, 1, MPI_INT, 0, MPI_COMM_WORLD);
	if (rank == 0) {
		cout << "After gather..." << "\n";
		for (int i = 0; i < size; i++) {
			cout << buffer[i] << " ";
		}
	}

	cout << "\n";
	MPI_Finalize();
	return 0;


}