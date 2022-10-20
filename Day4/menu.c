#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#define NormalPen 0x0F
#define HighLightPen 0XF0
#define Enter 0x0D
#define ESC 27
#define Down 80
#define UP 72

void gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE),
        coord);
}
void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

int main(int argc, char const *argv[])
{
    char inp, ExitFlag = 0;
    char choices[3][10] = {" New ", "Save", "Exit"};
    int current = 0;
    do
    {
        textattr(NormalPen);
        system("cls");
        for (int i = 0; i < 3; i++)
        {
            gotoxy(15, 10 + 3 * i);
            if (current == i)
            {
                textattr(HighLightPen);
            }
            else
            {
                textattr(NormalPen);
            }
            printf(choices[i]);
        }
        inp = _getche();
        switch (inp)
        {
        case ESC:
            ExitFlag = 1;
            break;
        case Enter:
            if (current == 2)
                ExitFlag = 1;
            else if (current == 1)
                ;
            else
                ;

            break;

        case -32:
            inp = _getche();
            switch (inp)
            {
            case UP:
                current--;
                if (current < 0)
                {
                    current = 2;
                }

                break;
            case Down:
                current++;
                if (current > 2)
                {
                    current = 0;
                }
                break;

            default:
                break;
            }
            break;
        default:
            break;
        }
    } while (!ExitFlag);

    textattr(NormalPen);
    system("cls");
    return 0;
}