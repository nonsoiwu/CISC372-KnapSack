/*
	The Memory function is aligned to 64 byte boundary between values so that
	the contents of the Memory Function "F" are spaced far enough to correct
	False Sharing. 
	
	Note the __attribute__ compiler directive for this purpose in the 'elem' struct
	//so that we can index "F" as a normal 2D array whist the compiler takes care
	//of indirect addressing and any extra offsetting required (Instead of explicit mention).

	Function used to allocate Dynamic Memory:
		void *memalign(size_t alignment, size_t size); //of malloc.h

	On event of a failure or crash => You may have to use Intel/AMD specific directives & prototype
	To work with icc: check __declspec(align(n)) directive as well as
	_aligned_malloc and _aligned_free to deal with heap memory

*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <malloc.h>
#include <time.h>

typedef struct {
    int x;
} __attribute__((aligned(64))) elem;

int MFKnapsack(int, int); //Function returning the optimal value for a given n and W
int max(int, int);
int n;
int* weights;
int* values;
int W;
elem **F;

int main()
{	
	printf("Parallel\n");
	scanf("%d", &n);
    printf("%d\n", n);
	weights = (int*)malloc((n+1)*sizeof(int));
	values = (int*)malloc((n+1)*sizeof(int));
	int i, j;
	//Read weights and corresponding values for 'n' items
	for(i=1;i<=n;i++)
		scanf("%d", &weights[i]);
        printf("weight %d\n", &weights[i]);
	for(i=1;i<=n;i++)
		scanf("%d", &values[i]);
        printf("val %d\n", &values[i]);
	//Read Max. Weight Capacity of Knapsack
	scanf("%d", &W);
    printf("Cap %d\n", W);
	//Allocating memory for the Memory Function
	F = (elem**)malloc((n+1)*sizeof(elem*));
	//64 => boundary width to the next element	
	for(i=0;i<=n;i++)
		F[i] = (elem*)memalign(64,(W+1)*sizeof(elem));

	clock_t begin = clock();
	//Zeroing out the first row	
	for(i=0;i<(W+1);i++)
		(*(F) + i ) -> x = 0; 
	//Zeroing out the first column	
	for(i=0;i<(n+1);i++)
		(*(F+i)) -> x = 0;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=W;j++)
			(*(F + i) + j) -> x = -1;
	}

	int res;
	#pragma omp parallel
	{
		#pragma omp single nowait
		{
			res = MFKnapsack(n, W); //Optimal value for items with given weights and values
		}
	}

	clock_t end = clock();

	printf("Optimal value= %d\n", res);
	double timer = 0.0 + (double)(end-begin)/CLOCKS_PER_SEC;
	printf("Execution Time: %fs", timer);
	
	//printf("Time taken = %lfs",(double)(end-start));
	free(weights);
	free(values);
	return 0;
}
int MFKnapsack(int i, int j)
{
	int value;
	if( ((*(F + i) + j)->x) < 0)
	{
		if(j < weights[i])  //If weight of item is more than current capacity
			value = MFKnapsack(i-1, j); //Value of previous item
		else
		{
			int a;
			int b;
		

				#pragma omp parallel sections
				{
					//Two sections that can run independently and simultaneously
					#pragma omp  section
					{
						a = MFKnapsack(i-1, j);
					}
					#pragma omp  section
					{
						b =  (values[i] + MFKnapsack(i-1, j - weights[i]));
					}
				}
				value = max(a,b);
			
			
		}
		(*(F + i) + j)->x = value;
	}
	return (*(F + i) + j)->x;
}

int max(int a, int b)
{
	return (a>b?a:b);
}