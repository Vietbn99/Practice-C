/*
    S(n) = x + x^2/2! + x^3/3! + … + x^n/N!
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int x, n;
    int multiply = 1;
    double sum;
    printf("INPUT: x = ");
    scanf("%d", &x);
    printf("INPUT: n = ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        multiply *= i;
        sum += pow(x, i) / (1.0 * multiply);
    }
    printf("OUTPUT: S(%d) = %.5lf\n", n, sum);
    return 0;
}