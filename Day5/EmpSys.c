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

// Global Variables
struct Employee EArr[10];
int MenuCurrent = 0, ExitFlag = 0, currentView = 0; // 0 main

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
void showMainMenu()
{
    printf("working");
    char choices[6][15] = {" New ", "DisplayByID", "DisplayAll", "DeleteByID", "DeleteAll", "Exit"};
    textattr(NormalPen);
    system("cls");
    for (int i = 0; i < 6; i++)
    {
        gotoxy(15, 10 + 3 * i);
        if (MenuCurrent == i)
        {
            textattr(HighLightPen);
        }
        else
        {
            textattr(NormalPen);
        }
        printf(choices[i]);
    }
}
void initId()
{
    for (int i = 0; i < 10; i++)
    {
        EArr[i].id = -1;
    }
}
void Init()
{
    showMainMenu();
    initId();
}
void updateMainMenu()
{
    char inp;
    inp = _getche();
    switch (inp)
    {
    case ESC:
        ExitFlag = 1;
        break;
    case Enter:
        //" New ", "DisplayByID", "DisplayAll", "DeleteByID", "DeleteAll", "Exit"
        if (MenuCurrent == 0)
            showInputForm();
        else if (MenuCurrent == 1)
            showEmpByID();
        else if (MenuCurrent == 2)
            showAllEmp();
        else if (MenuCurrent == 3)
            DeleteEmpById();
        else if (MenuCurrent == 4)
            DeleteAllEmp();
        else if (MenuCurrent == 5)
            ExitFlag = 1;
        break;

    case -32:
        inp = _getche();
        switch (inp)
        {
        case UP:
            MenuCurrent--;
            if (MenuCurrent < 0)
                MenuCurrent = 5;
            break;
        case Down:
            MenuCurrent++;
            if (MenuCurrent > 5)
                MenuCurrent = 0;
            break;
        }
        break;
    }
    showMainMenu();
}
void showInputForm()
{
    char returnFlag = 0;
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
        gotoxy(40, 10 + 3 * i);
        printf(inpFeilds[i + 5]);
    }
}
void receiveInput(int EmpId)
{
}
void showEmpByID() {}
void showAllEmp() {}
void DeleteEmpById() {}
void DeleteAllEmp() {}

int main()
{
    Init();
    int temp;
    do
    {
        switch (currentView)
        {
        case 0:
            updateMainMenu();
            break;
        case 1:
            printf("Please Choose EmpID between 1 and 10 : ");
            scanf("%i", temp);
            showInputForm();
            receiveInput(temp - 1);
            showMainMenu();
            currentView = 0;
            break;
        default:
            break;
        }
    } while (!ExitFlag);

    return 0;
}
