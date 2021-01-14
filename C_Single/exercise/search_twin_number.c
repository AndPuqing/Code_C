/*
要求实现一个函数，统计给定区间内的三位数中有两位数字相同的完全平方数（如144、676）的个数。
函数接口定义： int search(int n);
其中传入的参数int n是一个三位数的正整数（最高位数字非0）。函数search返回[101, n] 区间内所有满足条件的数的个数。
*/

#include <stdio.h>
#include <math.h>

int search(int n);

int main()
{
    int number;

    scanf("%d", &number);
    printf("count=%d\n", search(number));

    return 0;
}

int search(int n)
{
    int num = 0; //计数量
    for (int i = 101; i <= n; i++)
    {
        int N = i;                     //操作量
        int boo = 0;                   //布尔量
        for (int j = 1; N > 0; j += 2) //检查是否为平方数，具体为等差数列求和
        {
            N -= j;
            if (N == 0)
                boo = 1;
        }
        if (boo && ((i % 10 == i / 100) || (i / 100 == i / 10 % 10) || (i % 10 == i / 10 % 10))) //等数判断
        {
            num++;
        }
    }
    return num;
}