#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;
    
    printf("Integer max value: %d\nSize of integer: %lu\n\n", a, sizeof(a));
    printf("Float max value: %f\nSize of float: %lu\n\n", b, sizeof(b));
    printf("Double max value: %f\nSize of double: %lu\n\n", c, sizeof(c));

    return 0;
}