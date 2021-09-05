#include<omp.h>

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	printf("Enter count of elements: ");
	scanf("%d",&n);
	int a[n],c[n],i;
	
	for(i=0;i<n;i++)
	{
		a[i] = i;
	}
	
	int scalar;
	printf("\nEnter scalar: ");
	scanf("%d",&scalar);
	
	#pragma omp parallel for shared(a,scalar,c) num_threads(n/3)
	for(i=0;i<n;i++)
	{
		c[i] = a[i] + scalar;
		printf("Thread-%d executes an operation on Array elements at position %d\n", omp_get_thread_num(), i);
	}
	
	printf("i\ta[i]\t+\tscalar\t=\tc[i]\n");
    for(i=0; i<n; i++) {
		printf("%d\t%d\t\t%d\t\t%d\n", i, a[i], scalar, c[i]);
    }
	return 0;
}
