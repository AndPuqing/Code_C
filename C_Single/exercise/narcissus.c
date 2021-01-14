#include <stdio.h>

int narcissistic(int number);
void PrintN(int m, int n);

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    if (narcissistic(m))
        printf("%d is a narcissistic number\n", m);
    PrintN(m, n);
    if (narcissistic(n))
        printf("%d is a narcissistic number\n", n);

    return 0;
}

int narcissistic(int number)
{
    int boo = 0;
    int vec = number;
    int length = 0;
    while (vec != 0)
    {
        vec /= 10;
        length++;
    }
    vec = number;
    int sum = 0;
    int temp = 0;
    do
    {
        temp = vec % 10;
        int a = temp;
        for (int i = 0; i < length - 1; i++)
        {
            temp *= a;
        }
        sum += temp;
        vec /= 10;
    } while (vec != 0);
    if (sum == number)
    {
        boo = 1;
    }
    return boo;
}
void PrintN(int m, int n)
{
    for (int i = m; i < n; i++)
    {
        if (narcissistic(i) == 1)
        {
            printf("%d\n", i);
        }
    }
}