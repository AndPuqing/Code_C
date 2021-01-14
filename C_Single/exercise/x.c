#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int cmpfunc(const void *a, const void *b) //作为快排函数
{
    return (*(int *)a - *(int *)b);
}
int *buildNumberLink(int min, int max) //生成数字递增链
{
    int length = max - min + 1; //实际上是常数 =inputNumber
    int *p = (int *)malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++)
    {
        p[i] = min++;
    }
    return p;
}
int sum(int *a, int *b, int length) //求消费分和
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += abs(a[i] - b[i]);
    }
    return sum;
}
int main()
{
    int *inputold;   //原输入数据
    int inputNumber; //数据个数
    scanf("%d", &inputNumber);
    inputold = (int *)malloc(sizeof(int) * inputNumber);
    fflush(stdin); //清空缓冲区
    for (int i = 0; i < inputNumber; i++)
    {
        scanf("%d", &inputold[i]);
        getchar();
    }
    int *inputnew = (int *)malloc(sizeof(int) * inputNumber); //建立操作数组
    memcpy(inputnew, inputold, sizeof(int) * inputNumber);    //内存拷贝
    qsort(inputnew, inputNumber, sizeof(int), cmpfunc);       //快速排序，找最大，最小值
    int min = inputnew[0];
    int max = inputnew[inputNumber - 1];
    int desent = max - min;        //最大最小差
    if (desent == inputNumber - 1) //如果等间距。最小代价就是原递增链
    {
        int *p = buildNumberLink(min, max);
        printf("%d ", sum(p, inputnew, inputNumber));
        free(p);
        free(inputnew);
        free(inputold);
    }
    if (desent > inputNumber - 1) //如果大于间距，将调整范围到最小代价
    {
        int sumMin = 9999;
        int lenTemp = desent - inputNumber + 1; //将向内缩
        for (int i = 0; i < lenTemp; i++)
        {
            for (int j = 0; j < lenTemp - i; j++)
            {
                int *p = buildNumberLink(min + i, max - j);
                int temp = sum(p, inputnew, inputNumber);
                free(p);
                if (temp < sumMin)
                {
                    sumMin = temp;
                }
            }
        }
        printf("%d ", sumMin);
        free(inputnew);
        free(inputold);
    }
    if (desent < inputNumber - 1)
    {
        int sumMin = 9999;
        int lenTemp = inputNumber - 1 - desent; //将外内缩
        for (int i = 0; i < lenTemp; i++)
        {
            for (int j = 0; j < lenTemp - i; j++)
            {
                int *p = buildNumberLink(min - i, max + j);
                int temp = sum(p, inputnew, inputNumber);
                free(p);
                if (temp < sumMin)
                {
                    sumMin = temp;
                }
            }
        }
        printf("%d ", sumMin);
        free(inputnew);
        free(inputold);
    }
}