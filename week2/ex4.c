#include <stdio.h>

void swap(int* a, int* b){
    
    int t;
    t = *a;
    *a = *b;
    *b = t;
    
}

int main(int argc, char **argv)
{
    
    int x, y;
    scanf("%d %d", &x, &y);
    printf("\nfirst: %d, second: %d\n", x, y);

    swap(&x, &y);

    printf("first: %d, second: %d", x, y);
    
    return 0;
}