/*
    S(n) = x + x^2 + x^3 + … + x^n
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int x, n;
    int sum = 0;
    printf("INPUT: x = ");
    scanf("%d", &x);
    printf("INPUT: n = ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        sum += pow(x, i);
    }
    printf("OUTPUT: S(%d) = %d\n", n, sum);
    return 0;
}