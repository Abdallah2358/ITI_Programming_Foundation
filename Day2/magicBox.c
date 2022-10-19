#include <stdio.h>
#include <windows.h>

void gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE),
        coord);
}

int main(int argc, char const *argv[])
{
    int i, Y, X, n, startY;

    do
    {
        printf("Please enter size of MAGIC BOX !! : ");
        scanf("%i", &n);

    } while (n < 3 || (n % 2 == 0));

    Y = 1, X = n / 2 + 1, startY = Y;
    gotoxy(0, 0);
    for (i = 1; i <= n * n; i++)
    {

        gotoxy(X * 3 + 7, Y * 2 + 3);
        printf("%i", i);
        if (i % n == 0)
        {
            Y++;
            if (Y > n)
                Y = 1;
        }
        else
        {
            Y--;
            X--;
            if (Y < 1)
                Y = n;
            if (X < 1)
                X = n;
        }
    }
    // No idea why but it works
    // while(startY--){
    //     printf("\n");
    // }

    return 0;
}
