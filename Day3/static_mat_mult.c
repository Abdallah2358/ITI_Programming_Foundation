#include <stdio.h>
#define ra 3
#define rb 2
#define ca 2
#define cb 1
int main(int argc, char const *argv[])
{
    // inti mat with received sizes
    int matA[ra][ca];
    int matB[rb][cb];
    int res[ra][cb];

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
