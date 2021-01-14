/*生成数字金字塔
*我的思路每层先输出空格，再输出数字加空格
*如输入n为3，则第一层先输出两个空格，加一个'1 '，如此便有规律
*/
#include <stdio.h>

void pyramid(int n);

int main()
{
    int n;

    scanf("%d", &n);
    pyramid(n);

    return 0;
}

void pyramid(int n)
{
    int m = n - 1;
    for (int i = 1; i <= n; i++) //层数次数
    {
        for (int j = 1; j <= m; j++) //输出空格m减一个
        {
            printf(" ");
        }
        m--;                         //空格为递减
        for (int x = 1; x <= i; x++) //输出层数个数字
        {
            printf("%d ", i);
        }
        printf("\n");
    }
}