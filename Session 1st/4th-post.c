/*
    S(n) = ½ + ¼ + … + 1/2n
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
        sum += (1 / (2 * i * 1.0));
    }
    printf("Output: S(%d) = %.5lf", n, sum);
    return 0;
}