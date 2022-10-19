#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i = 0, sum = 0;
    while (sum < 100)
    {
        printf("Please enter to add to the sum : ");
        scanf("%i", &i);
        sum += i;
        printf("Now Your sum = %i", sum);
    }
    printf("Congrats Your sum exceeded 100 and sum = %i", sum);

    return 0;
}
