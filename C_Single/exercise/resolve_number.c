//分解整数，较麻烦,完整
#include <stdio.h>

int main()
{
    int n;
    int length = 1;
    scanf("%d", &n);
    int y = n;
    while (y >= 10)
    {
        y /= 10;
        length++;
    }
    for (int i = length - 1; i >= 1; i--)
    {
        int x = n;
        for (int j = 1; j <= i; j++)
        {
            x /= 10;
        }
        printf("%d ", x);
        for (int j = 1; j <= i; j++)
        {
            x *= 10;
        }
        n = n - x;
    }
    printf("%d", n);
    return 0;
}