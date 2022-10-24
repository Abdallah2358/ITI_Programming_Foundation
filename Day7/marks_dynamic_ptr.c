#include <stdio.h>

int main(int argc, char const *argv[])
{
    int **Marks, stdN, subN, i, j, *sum, *avg;
    printf("Enter Student Numer: \n");
    scanf("%i", &stdN);
    Marks = (int **)malloc(stdN * sizeof(int *));
    sum = (int *)malloc(stdN * sizeof(int *));
    printf("Enter Subjects Number");
    scanf("%i", &subN);
    for (int i = 0; i < stdN; i++)
    {
        Marks[i] == (int *)malloc(subN * sizeof(int));
        avg = (int *)malloc(subN * sizeof(int));
    }
    for (int i = 0; i < stdN; i++)
        sum[i] = 0;
    for (int i = 0; i < subN; i++)
        avg[i] = 0;
    for (int i = 0; i < stdN; i++)
    {
        for (int j = 0; j < subN; j++)
        {
            printf("Subject %i, Student %i", j + 1, i + 1);
            scanf("%i", Marks[i][j]);
            sum[i] += Marks[i][j];
            avg[j] += Marks[i][j];
        }
    }
    for (int j = 0; j < subN; j++)
    {
        avg[j] /= stdN;
    }
    for (int i = 0; i < stdN; i++)
    {
        free(Marks[i]);
    }
    free(Marks);
    free(sum);
    free(avg);

    return 0;
}
