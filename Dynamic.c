// OpenMP header
#include<omp.h>

#include<stdio.h>
#include<stdlib.h>

int main() {
    
  int a[1000];
  int b[1000];
  int c[1000];
  int count = 0;
  double time = omp_get_wtime();
  
  //omp_set_num_threads(2);

  for(int i=0;i<1000;i++)
  {
    a[i]=i;
    b[i]=i+1;
  }

  #pragma omp parallel for schedule(dynamic)
  for(int i=0;i<1000;i++) {
    c[i] = a[i] + b[i];
   //printf("\n %d th Thread executes %d index",omp_get_thread_num(),i);
    count++;
  }
  
  
  for(int i=0;i<1000;i++)
    printf("%d ",c[i]);
    
  printf("\n \n %d Times loop executed",count);
  printf("\n Using %d no of threads with DYNAMIC SCHEDULE and %f execution time",omp_get_max_threads(),omp_get_wtime() - time);

  return 0;
  
}
