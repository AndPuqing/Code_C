/*要求实现一个用递归计算1+2+3+…+n的和的简单函数。
函数接口定义：
int sum( int n );
该函数对于传入的正整数n返回1+2+3+…+n的和；若n不是正整数则返回0。题目保证输入输出在长整型范围内。建议尝试写成递归函数。
*/

#include <stdio.h>

int sum(int n);

int main()
{
    int n;

    scanf("%d", &n);
    printf("%d\n", sum(n));

    return 0;
}

int sum(int n)
{
    if (n > 0)
    {
        if (n == 1)
        {
            return 1;
        }
        return sum(n - 1) + n;
    }
    else
    {
        return 0;
    }
}