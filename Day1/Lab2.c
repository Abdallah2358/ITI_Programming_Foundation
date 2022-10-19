#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int inp;
    printf("please enter a number: ");
    scanf("%i", &inp);
    printf("As a Hex %x\n", inp);
    printf("As a Char %c\n", inp);

    return 0;
}
