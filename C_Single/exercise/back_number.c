//翻转整数
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
    printf("%d", temp);
    return 0;
}