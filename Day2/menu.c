#include <stdio.h>
int main(int argc, char const *argv[])
{
    int sel;
    printf("Please Choose a number between the following");
    printf("\na. Fish");
    printf("\nb. Meat");
    printf("\nc. Salad\n");

    scanf("%c", &sel);
    switch (sel)
    {
    case 'a':
        printf("You choose Right We Have the best Fish in the world ");
        break;

    case 'b':
        printf("You choose Right, Our Meat is top Rated");
        break;

    case 'c':
        printf("You choose Right, Stop Eating meat is 1st to Stop global warming");
        break;

    default:
        printf("Thanks For your Visit");
        break;
    }
    return 0;
}
