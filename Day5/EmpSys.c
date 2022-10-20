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
    int age;
    char name[100];
    char address[200];
    char gender[8];
    double salary;
    double overTime;
    double tax;
};

// Global Variables
struct Employee EArr[10];
int MenuCurrent = 0, ExitFlag = 0, currentView = 0; // 0 main
// emp func
void printEmpData(empID)
{
    struct Employee temp;
    printf("Employee #%i\nName : %s ,Age: %d ,Gender: %s ,Salary : %lf ,Over Time : %lf ,Tax : %lf ,Address : %s ",
           temp.id, temp.name, temp.age, temp.gender, temp.salary, temp.overTime, temp.tax, temp.address);
}

// Writing to console Functions
void gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
void clearScreen()
{
    textattr(NormalPen);
    system("cls");
}

// Main Menu Functions
void showMainMenu()
{
    clearScreen();
    char choices[6][15] = {" New ", "DisplayByID", "DisplayAll", "DeleteByID", "DeleteAll", "Exit"};
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
            currentView = 1;
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

// Initialization Functions
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

// Input Functions

char isIdExist(int empId)
{
    return EArr[empId].id != -1;
}

int chooseEmpID()
{
    clearScreen();
    int temp;
    do
    {
        printf("Please Choose EmpID between 1 and 10 : ");
        scanf("%i", &temp);
        if (isIdExist(temp))
        {
            printf("\nThis ID already used.\n");
        }

    } while (isIdExist(temp));
    return temp;
}

void showInputForm()
{
    clearScreen();
    char returnFlag = 0;
    char inpFields[8][15] = {"Name :", "Salary :", "Tax :", "Address :", "Age :", "Gender :", "Over Time :"};
    int shift = 3;
    for (int i = 0; i < 4; i++)
    {
        gotoxy(5, 10 + 3 * i);
        printf(inpFields[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        gotoxy(40, 10 + 3 * i);
        printf(inpFields[i + 5]);
    }
}
void receiveFormInput(int empID)
{
    struct Employee temp;
    temp.id = empID;
    gotoxy(15, 10);
    scanf("%s", temp.name);
    gotoxy(15, 13);
    scanf("%lf", &temp.salary);
    gotoxy(15, 16);
    scanf("%lf", &temp.tax);
    gotoxy(15, 19);
    scanf("%s", temp.address);

    gotoxy(55, 10);
    scanf("%i", &temp.age);
    gotoxy(55, 13);
    scanf("%s", temp.gender);
    gotoxy(55, 19);
    scanf("%lf", &temp.overTime);
    EArr[empID] = temp;
}
void showNetSalary(int id)
{
    clearScreen();
    double net = EArr[id].salary + EArr[id].overTime - EArr[id].tax;
    printf("Employee #%i Net Salary : %lf", id, net);
    printf("Press Any key to return to main menu");
    _getch();
}
void showEmpByID()
{
}
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
            temp = chooseEmpID(); // a waste of 4 bytes :(
            showInputForm();
            receiveFormInput(temp);
            showNetSalary(temp);
            showMainMenu();
            currentView = 0;
            break;
        default:
            break;
        }
    } while (!ExitFlag);

    return 0;
}
