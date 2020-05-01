/*
    List all "divisors" of positive integers n
*/
#include <stdio.h>
int main()
{
    int n;
    printf("INPUT: n = ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            printf("%d\t%d\t", i, 0 - i);
        }
    }
    return 0;
}