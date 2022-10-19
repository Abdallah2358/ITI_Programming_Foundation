#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

int main(int argc, char const *argv[])
{
    char FirstName[10], LastName[10];
    printf("Please enter your first name :");
    scanf("%s", FirstName);
    printf("Please enter your last name :");
    scanf("%s", LastName);

    strcat(FirstName, " ");
    strcat(FirstName, LastName);
    printf("Hello %s", FirstName);

    return 0;
}
