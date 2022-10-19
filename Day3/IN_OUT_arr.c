#include <stdio.h>
int main(int argc, char const *argv[])
{
    int  arr [4];
    printf("Please enter the ages of your 4 best people\n");
    for (int i = 0; i < 4; i++)
    {
        printf("age of your num %i : ",i+1);
        scanf("%i\n", &arr[i]);
        printf("\n");
    }

    printf("Here comes the ages of your 4 best people\n");
    for (int i = 0; i < 4; i++)
    {
        printf("age of your num %i : %i years \n", i+1, arr[i]);
    }
    return 0;
}
