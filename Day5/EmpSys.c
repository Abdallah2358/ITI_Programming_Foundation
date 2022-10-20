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

struct Employee
{
    int id;
    char name[100];
    double salary;
    double tax;
    char address[150];
    int age;
    char gender[8];
    double overTime;
};

struct Employee EArr[10];

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
void showInputForm()
{
    textattr(NormalPen);
    system("cls");

    char inpFeilds[8][15] = {"ID", "Name", "Salary", "Tax", "Address", "Age", "Gender", "Over Time"};
    int shift = 3;
    for (int i = 0; i < 5; i++)
    {
        gotoxy(5, 10 + 3 * i);
        printf(inpFeilds[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        gotoxy(5, 10 + 3 * i);
        printf(inpFeilds[i + 5]);
    }
}
void showEmpByID() {}
void showAllEmp() {}
void DeleteEmpById() {}
void DeleteAllEmp() {}
void menu()
{
    char inp, ExitFlag = 0;
    char choices[6][15] = {" New ", "DisplayByID", "DisplayAll", "DeleteByID", "DeleteAll", "Exit"};
    int current = 0;
    do
    {
        textattr(NormalPen);
        system("cls");
        for (int i = 0; i < 6; i++)
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
            //" New ", "DisplayByID", "DisplayAll", "DeleteByID", "DeleteAll", "Exit"
            if (current == 0)
                showInputForm();
            else if (current == 1)
                showEmpByID();
            else if (current == 2)
                showAllEmp();
            else if (current == 3)
                DeleteEmpById();
            else if (current == 4)
                DeleteAllEmp();
            else if (current == 5)
                ExitFlag = 1;
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
                    current = 5;
                }

                break;
            case Down:
                current++;
                if (current > 5)
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
}

/// 112 Byte

int main()
{
    int i;

    menu();
    /*  for (i = 0; i < 3; i++)
     {
         printf("Enter Employee ID : \n");
         scanf("%i", &EArr[i].ID);
         _flushall();
         printf("Enter Employee Name : \n");
         gets(EArr[i].Name);
         _flushall();
         printf("Enter Employee Salary : \n");
         scanf("%lf", &EArr[i].Salary);

         printf("%i .Employee : %s , Salary %lf", EArr[i].ID, EArr[i].Name, EArr[i].Salary);

         _getch();
         system("cls");
     } */
    /*

    struct Employee E; ///Allocation 112 Byte in Main Stack Frame

    E.ID = -1 ;

    printf("Enter Employee ID : \n");
    scanf("%i" , &E.ID);
    _flushall();
    printf("Enter Employee Name : \n");
    gets(E.Name);
    _flushall();
    printf("Enter Employee Salary : \n");
    scanf("%lf" , &E.Salary);

    printf("%i .Employee : %s , Salary %lf",E.ID , E.Name , E.Salary);
*/
    return 0;
}
