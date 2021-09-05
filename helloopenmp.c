#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{
	#pragma omp parallel
	{
		printf("Hello from Abhay to Thread: %d\n",omp_get_thread_num());
	}
}