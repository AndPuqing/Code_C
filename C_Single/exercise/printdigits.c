/*实现一个函数，对一个整数进行按位顺序输出。
函数接口定义：void printdigits( int n );
函数printdigits应将n的每一位数字从高位到低位顺序打印出来，每位数字占一行。
*/
#include <stdio.h>

void printdigits(int n);

int main()
{
    int n;

    scanf("%d", &n);
    printdigits(n);

    return 0;
}

void printdigits(int n)
{
    if (n < 10)
    { //出口
        printf("%d\n", n);
    }
    else
    { //123456-12345-1234-123-12-1  然后1-1  12%10-2 123%10-3  .....输出1 2 3 4 5 6
        printdigits(n / 10);
        printf("%d\n", n % 10); // 这样的顺序    当输入123456  出来 1 2 3 4 5 6   说明123456/10 一直整除到6
                                //如果交换        123456  输出  6 5 4 3 2 1
    }
}