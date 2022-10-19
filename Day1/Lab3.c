#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char chr;
    printf("Enter a character: ");
    scanf("\n%c", &chr);
    printf("\nAs Hex %x", chr);
    printf("\nAs Int %i", chr);

    return 0;
}
