/*完成大小排序，选择排序*/

#include <stdio.h>

void swap(int *a, int *b);

int main()
{
    int a[3];
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &a[i]);
    }
    //输入数组
    for (int i = 0; i < 2; i++)
    { /*由于数组长度为n，只需要n-1次遍历就可比较完
        这里要注意，将最大或者最小放在头或尾（无序前后一位）
        所以，这里i的作用就是放最大小值的下标
        */
        //int maxNUM = a[i];
        //记录最大的数值
        for (int j = i + 1; j < 3; j++)
        { //进行数组遍历
            if (a[j] > a[i])
            { //如果比最大的值大
                //maxNUM = a[j];
                //记录最大值
                swap(&a[i], &a[j]);
                //进行交换
            }
        }
    }
    for (int i = 0; i < 3; i++)
    { //输出
        printf("%d", a[i]);
    }
}
void swap(int *a, int *b)
{ //交换
    int temp = *a;
    *a = *b;
    *b = temp;
}
