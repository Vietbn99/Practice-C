#include <stdio.h>

int main()
{
    // Bài 1: S(n) = 1 + 2 + 3 + … + n
    int sum1 = 0, n1;
    printf("INPUT n1 = ");
    scanf("%d", &n1);
    for (int i = 0; i <= n1; i++)
    {
        sum1 += i;
    }
    printf("S(%d) = %d\n", n1, sum1);

    // Bài 2: S(n) = 1^2 + 2^2 + … + n^2
    int n2;
    int sum2 = 0;
    printf("INPUT n2 = ");
    scanf("%d", &n2);
    for (int i = 0; i <= n2; i++)
    {
        sum2 += pow(i, 2);
    }
    printf("S(%d) = %d\n", n2, sum2);
    return 0;
}