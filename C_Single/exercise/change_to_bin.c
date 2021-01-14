/*要求实现一个函数，将正整数n转换为二进制后输出。
函数接口定义： void dectobin(int n);
函数dectobin应在一行中打印出二进制的n。建议用递归实现。
*/

#include <stdio.h>

void dectobin(int n);

int main()
{
    int n;

    scanf("%d", &n);
    dectobin(n);

    return 0;
}

void dectobin(int n)
{
    if (n == 0)
        printf("0");
    int boo = 0;
    unsigned mask = 1u << 31; //这里u是指unsigned,1向左位移31位
    for (; mask; mask >>= 1)
    {
        if (n & mask ? 1 : 0 == 1)
        {
            boo = 1;
        }
        if (boo)                            //这里mask 是一个布尔操作值，不为0就ture，操作向右移1位
            printf("%d", n & mask ? 1 : 0); //打印数，这里用的条件表达式，如果ture为1，false为0
    }
}