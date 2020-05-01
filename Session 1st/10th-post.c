/*
    Find the greatest odd divisor of a positive integer n. 
    For example n = 100 the greatest old divisor is 25
*/
#include <stdio.h>
int main()
{
    int n;
    printf("INPUT n = ");
    scanf("%d", &n);
    if (n % 2 != 0)
    {
        printf("%d", n);
    }
    else
    {
        for (int i = n / 2; i > 0; i--)
        {
            if (n % i == 0 && i % 2 != 0)
            {
                printf("%d", i);
                break;
            }
        }
    }
    return 0;
}