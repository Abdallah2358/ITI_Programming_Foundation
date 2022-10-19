#include <stdio.h>
#define y 2
#define x 3

int main(int argc, char const *argv[])
{
    int arr[y][x];
    int sumArr[y] = {0};
    printf("Please enter the numbers\n");
    for (int i = 0; i < y; i++)
    {
        printf("\nNow you are entering Row %i values : \n", i + 1);
        for (int j = 0; j < x; j++)
        {
            printf("Please enter Values %i : ", j + 1);
            scanf("%i", &arr[i][j]);
            sumArr[i] += arr[i][j];
        }
        printf("\t=========================\n", i);
    }

    for (int i = 0; i < y; i++)
    {
        printf("\nSum of Row %i values : %i", i + 1, sumArr[i]);
        printf("\nAverage  of Row %i values : %f", i + 1, (sumArr[i] / ((double)x)));
    }
    return 0;
}
