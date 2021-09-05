#include<omp.h>

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	printf("Enter count of elements: ");
	scanf("%d",&n);
	int a[n],b[n],c[n],i;
	
	for(i=0;i<n;i++)
	{
		a[i] = i;
		b[i] = i + 10;
	}
	
	#pragma omp parallel for shared(a,b,c) num_threads(n/3)
	
		for(i=0;i<n;i++)
		{
			c[i] = a[i] + b[i];
			printf("Thread-%d executes an operation on Array elements at position %d\n", omp_get_thread_num(), i);
		}
    
	
	printf("i\ta[i]\t+\tb\t=\tc[i]\n");
    for(i=0; i<n; i++) {
		printf("%d\t%d\t\t%d\t\t%d\n", i, a[i], b[i], c[i]);
    }
	return 0;
}
