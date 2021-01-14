//分解整数，先倒序，在输出
#include <stdio.h>

int main()
{
    int n;
    int temp = 0;
    scanf("%d", &n);
    do
    {
        int t = n % 10;
        temp = temp * 10 + t;
        n = n / 10;
    } while (n != 0);
    do
    {
        if (temp > 9)
        {
            printf("%d ", temp % 10);
        }
        else
        {
            printf("%d", temp);
        }
        temp /= 10;
    } while (temp != 0);
    return 0;
}