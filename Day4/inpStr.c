#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

int main(int argc, char const *argv[])
{
    char str[10], i;
    for (int i = 0; i < 10; i++)
    {
        str[i] = _getche();
        if (str[i] == 13)
        {
            str[i] = '\0';
            break;
        }
    }

    printf("Your string is '%s'", str);
    return 0;
}
