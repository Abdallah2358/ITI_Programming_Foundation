#include <stdio.h>

char swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return 1;
}
int main(int argc, char const *argv[])
{
    int x = 15;
    int y = 58;
    printf("X = %i,\tY = %i\n", x, y);
    swap(&x, &y);
    printf("Values swapped");
    printf("X = %i,\tY = %i\n", x, y);
    return 0;
}
