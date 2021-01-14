//倒数交替相加
#include <stdio.h>

int main()
{
    int n;
    double add = 0;
    double f = 1.0;
    scanf("%d", &n);
    //更好写法
    // for (int i = 1; i <= n; i++)
    // {
    //     add += f / i;
    //     f = -f;
    // }

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            add -= 1.0 / i;
        }
        else
        {
            add += 1.0 / i;
        }
    }
    printf("answer is :%lf", add);
    return 0;
}