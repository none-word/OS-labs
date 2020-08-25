#include <stdio.h>

void printTriangle(int n){
    
    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j < n - 1 - i; j++){
            printf("%c", ' ');
        }
        
        for (int j = 0; j < 2 * i + 1; j++){
            printf("%c", '*');
        }
        
        printf("%c", '\n');
    }
    
}

int main(int argc, char **argv)
{
    
    int n;
    sscanf(argv[1], "%d", &n);

    printTriangle(n);
    return 0;
}