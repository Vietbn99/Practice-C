/*
    S(n) = 1 + x + x^3/3! + x^5/5! + … + x^(2n+1)/(2n+1)!
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int x, n;
    double sum = 1.0;
    int multiply = 1;
    printf("INPUT: x = ");
    scanf("%d", &x);
    printf("INPUT: n = ");
    scanf("%d", &n);
    int k = 1;
    for (int i = 0; i <= n; i++)
    {
        for (; k <= (2 * i + 1); k++)
        {
            multiply *= k;
        }
        k = 2 * i + 2;
        sum += pow(x, (2 * i + 1)) / (1.0 * multiply);
    }
    printf("OUTPUT: S(%d) = %.5lf\n", n, sum);
    return 0;
}