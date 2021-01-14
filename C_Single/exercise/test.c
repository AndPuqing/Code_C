#include <stdio.h>
#include <math.h>
void deal(int *pm, int m, int n)
{
    int i, k;
    int *pm1 = pm + m - 1;
    for (i = 0; i < m - 1; i++)
    {
        if (*pm1 <= *(pm + i))
        {
            k = *pm1;
            *pm1 = *(pm + i);
            *(pm + i) = k;
            k = *(pm1 + n);
            *(pm1 + n) = *(pm + i + n);
            *(pm + i + n) = k;
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[2][n];
    int *pi1 = &a[0][0];
    int *pi2 = pi1 + n - 1;
    int *pi3 = pi1 + n;
    int *pi4 = pi1 + n + n - 1;
    int *pi;
    for (pi = pi1; pi <= pi2; pi++)
    {
        scanf("%d", pi);
    }
    int i;
    for (i = 1; i <= n; i++)
    {
        *pi = i;
        pi += 1;
    }
    for (i = n; i >= 2; i--)
    {
        deal(pi1, i, n);
    }
    int x = 0;
    pi = pi3;
    for (i = 1; i <= n; i++)
    {
        x += abs(*pi - i);
        pi += 1;
    }
    printf("%d ", x);
    return 0;
}