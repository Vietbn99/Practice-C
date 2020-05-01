/*
    S(n) = 1 + 1.2 + 1.2.3 + … + 1.2.3….N
*/
#include <stdio.h>

int main()
{
    int n;
    long int sum = 0;
    long int multiply = 1;
    printf("INPUT n = ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        multiply *= i;
        sum += multiply;
    }
    printf("OUTPUT: S(%d) = %ld\n", n, sum);
    return 0;
}