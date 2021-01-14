//实现输入m和n，保证有m<n,输出m到n和
#include <stdio.h>

int sum(int m, int n);

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);
    printf("sum = %d\n", sum(m, n));

    return 0;
}

int sum(int m, int n)
{
    int add = 0;
    for (m; m <= n; m++)
    {
        add += m;
    }
    return add;
}