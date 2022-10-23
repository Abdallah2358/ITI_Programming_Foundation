#include <stdio.h>
int main(int argc, char const *argv[])
{
    int arr[3];
    int *ptr = arr;
    for (int i = 0; i < 3; i++)
    {
        printf("please enter next value : ");
        scanf("%i", ptr + i);
        printf("\n");
    }
    printf("Array values : \n");
    for (int i = 0; i < 3; i++)
    {
        printf("Array[i] = %i\t", *ptr + i);
    }

    return 0;
}
