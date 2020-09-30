#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <malloc.h>

void *reallocation(int *ptr, int size){

  if (size == 0){
    free(ptr);
    return NULL;
  }

  if (ptr == NULL){
    return (int*)malloc(size * sizeof(int));
  }

  int* a = (int*)malloc(size * sizeof(int));
  for (int i = 0; i < malloc_usable_size(ptr); i++){
    a[i] = ptr[i];
  }

  free(ptr);
  return a;
}

int main(){
	
  //Allows you to generate random number
	srand(time(NULL));

	// Allows user to specify the original array size, stored in variable n1.
	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	//Create a new array of n1 ints
	int* a1 = (int*)malloc(n1*sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		//Set each value in a1 to 100
		a1[i]=100;
		
		//Print each element out (to make sure things look right)
		printf("%d ", a1[i]);
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	//Dynamically change the array to size n2
	a1 = (int*)reallocation(a1, n2*sizeof(int));	

	for(i=0; i<n2;i++){
		//Print each element out (to make sure things look right)
		printf("%d ", a1[i]);
	}
	printf("\n");
	
	//Done with array now, done with program :D
	return 0;
}