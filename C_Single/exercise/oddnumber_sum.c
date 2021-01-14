//素数

#include <stdio.h>
#include <math.h>

int prime(int p);
int PrimeSum(int m, int n);

int main()
{
    int m, n, p;

    scanf("%d %d", &m, &n);
    printf("Sum of ( ");
    for (p = m; p <= n; p++)
    {
        if (prime(p) != 0)
            printf("%d ", p);
    }
    printf(") = %d\n", PrimeSum(m, n));

    return 0;
}

int prime(int p)
{
    int boo = 1;
    if (p > 0)
    {
        for (int i = 2; i < p; i++)
        {
            if (p % i == 0)
            {
                boo = 0;
                break;
            }
        }
    }
    else
    {
        boo = 0;
    }

    if (p == 1)
    {
        boo = 0;
    }
    return boo;
}
int PrimeSum(int m, int n)
{
    int sum = 0;
    for (m; m <= n; m++)
    {
        if (prime(m) == 1)
        {
            sum += m;
        }
    }
    return sum;
}