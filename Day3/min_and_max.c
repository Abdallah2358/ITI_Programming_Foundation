#include <stdio.h>
int main(int argc, char const *argv[])
{
    int arrsize, max = -2147483648, min = 2147483647;

    printf("Please enter how many numbers you will enter ?\n");
    scanf("%i", &arrsize);
    int arr[arrsize];

    printf("Please enter the numbers\n");
    for (int i = 0; i < arrsize; i++)
    {
        printf("Please enter %i : ", i + 1);
        scanf("%i", &arr[i]);

        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];

        printf("\n");
    }

    printf("The min of your array is %i\n", min);
    printf("The max of your array is %i\n", max);

    return 0;
}
