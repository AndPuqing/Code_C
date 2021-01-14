/*
实现一个计算Fibonacci数的简单函数，
并利用其实现另一个函数，输出两正整数m和n（0<m≤n≤10000）之间的所有Fibonacci数。
所谓Fibonacci数列就是满足任一项数字是前两项的和（最开始两项均定义为1）的数列。
其中函数fib须返回第n项Fibonacci数；
函数PrintFN要在一行中输出给定范围[m, n]内的所有Fibonacci数，
相邻数字间有一个空格，行末不得有多余空格。
如果给定区间内没有Fibonacci数，则输出一行“No Fibonacci number”。
*/

#include <stdio.h>

int fib(int n);
void PrintFN(int m, int n);

int main()
{
    int m, n, t;

    scanf("%d %d %d", &m, &n, &t);
    printf("fib(%d) = %d\n", t, fib(t));
    PrintFN(m, n);

    return 0;
}

int fib(int n)
{
    n -= 1;               //特别注意输入为第几项不是从0开始，所以减1
    int Fibo[10000] = {}; //Fibonacci数列生成
    Fibo[0] = 1;
    Fibo[1] = 1;
    for (int i = 2; i < 10000; i++) //填入数据
    {
        Fibo[i] = Fibo[i - 1] + Fibo[i - 2];
    }
    return Fibo[n];
}

void PrintFN(int m, int n)
{
    int boo = 0; //布尔控制函数
    for (int i = 0; i < 10000; i++)
    {
        if (fib(i) >= m && fib(i) <= n)
        {
            boo = 1;
            if (fib(i + 1) > n) //这里这么复杂是因为输出要求数据江有空格，但末尾没有空格
            {
                printf("%d", fib(i));
            }
            else
            {
                printf("%d ", fib(i));
            }
        }
    }
    if (boo == 0)
    {
        printf("No Fibonacci number");
    }
}