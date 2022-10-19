#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("This program Multiplies Matrix A by Matrix B\n");

    int ra, rb, ca, cb;

    // entering size of matrix
    do
    {
        printf("Please enter num of ROWS of Matrix A : ");
        scanf("%i", &ra);
        printf("\nPlease enter num of COLS of Matrix A : ");
        scanf("%i", &ca);
        printf("\n\n\nPlease enter num of ROWS of Matrix B : ");
        scanf("%i", &rb);
        printf("\nPlease enter num of COLS of Matrix B : ");
        scanf("%i", &cb);

    } while (ca != rb);

    // inti mat with received sizes
    int matA[ra][ca];
    int matB[rb][cb];
    int res[ra][cb] ;

    // filling matrix a
    printf("Please enter Mat A :\n");
    for (int i = 0; i < ra; i++)
    {
        printf("\nNow you are entering Row %i of Mat A : \n", i + 1);
        for (int j = 0; j < ca; j++)
        {
            printf("Please enter a%i,%i : ", i + 1, j + 1);
            scanf("%i", &matA[i][j]);
        }
        printf("\t=========================\n");
    }

    printf("\t=========================\n");
    printf("\t=========================\n");

    // filling matrix b
    printf("Please enter Mat B : \n");
    for (int i = 0; i < rb; i++)
    {
        printf("\nNow you are entering Row %i of Mat B : \n", i + 1);
        for (int j = 0; j < cb; j++)
        {
            printf("Please enter b%i,%i : ", i + 1, j + 1);
            scanf("%i", &matB[i][j]);
        }
        printf("\t=========================\n");
    }

    // multiplication
    int temp = 0;
    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < cb; j++)
        {
            for (int k = 0; k < ca; k++)
            {
                temp += (matA[i][k] * matB[k][j]);
            }
            res[i][j] = temp;
            temp = 0;
        }
    }

    // print result
    printf("Result Matrix\n");
    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < cb; j++)
        {
            printf("r%i,%i = %i \t", i + 1, j + 1, res[i][j]);
        }
        printf("\n");
    }

    return 0;
}
