#include <stdio.h>
#include <stdlib.h>

int main()
{
    int data = 10;
    int *ptr = &data;

    printf("Data: %d\n", *ptr);
    return 0;
}