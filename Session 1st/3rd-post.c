/*
    Bài 3: Tính S(n) = 1 + 1/2 + 1/3 + … + 1/n
*/
#include <stdio.h>

int main()
{
    int n;
    double sum = 0;
    printf("Input n = ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        sum += (1 / (i * 1.0));
    }
    printf("S(%d) = %.5lf", n, sum);
    return 0;
}