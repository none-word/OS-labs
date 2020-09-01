#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubble_sort(int *array, int size) {
    
    for (int i = 0; i < size - 1; i++) {
        
        for (int j = 0; j < size - i - 1; j++) {
            
            if (array[j] > array[j + 1]) {
                
                swap(&array[j + 1], &array[j]);
                
            }
            
        }
        
    }
    
}

int main(){
 
 int n;
 printf("Please, write length of the array\n");
 scanf("%d", &n);
 
 int array[n];
 
 printf("\nPlease, write elements of the array\n");
 for (int i = 0; i < n; i++) {
     scanf("%d", &array[i]);
 }
 
 bubble_sort(array, n);
 
 printf("\nSorting array\n");
 for (int i = 0; i < n; i++) {
     printf("%d ", array[i]);
 }
 
 return 0;
}