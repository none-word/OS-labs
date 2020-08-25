#include <stdio.h>
#include <string.h>

int main()
{
    
    char string[256];
    printf("Write string: ");
    fgets(string, 256, stdin);
    
    printf("\nReverse string: ");
    
    for (int i = strlen(string) - 1; i >= 0; i--){
        printf("%c", string[i]);
    }

    return 0;
}