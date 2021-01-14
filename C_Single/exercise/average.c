//实现输入整数，直到输入-1，输出个数于平均数
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int input = 0;
    int add;     //和
    float n = 0; //个数
    float ava;   //平均数
    scanf("%d", &input);
    //不是-1，累加
    while (input != -1)
    {
        add += input;
        n++;
        scanf("%d", &input);
    }
    //解决当直接输入-1情况
    if (n == 0)
    {
        ava = 0;
    }
    else
    {
        ava = add / n; //这里注意平均数的类型，add一定为整数，所以让n为浮点型
    }
    printf("The number is:%f\nAverage is:%f\n", n, ava);
    return 0;
}