//报数游戏是这样的：有n个人围成一圈，按顺序从1到n编好号。
//从第一个人开始报数，报到m（ < n）的人退出圈子；
//下一个人从1开始报数，报到m的人退出圈子。
//如此下去，直到留下最后一个人。
//本题要求编写函数，给出每个人的退出顺序编号。
//函数接口定义：
//void CountOff(int n, int m, int out[]);
//其中n是初始人数；m是游戏规定的退出位次（保证为小于n的正整数）。
//函数CountOff将每个人的退出顺序编号存在数组out[] 中。
//因为C语言数组下标是从0开始的，所以第i个位置上的人是第out[i - 1]个退出的。
//这个题目还是有点难度的，详看注解
#include <stdio.h>
#define MAXN 20

void CountOff(int n, int m, int out[]);

int main()
{
    int out[MAXN], n, m;
    int i;

    scanf("%d %d", &n, &m);
    CountOff(n, m, out);
    for (i = 0; i < n; i++)
        printf("%d ", out[i]);
    printf("\n");

    return 0;
}
/*我写这道题有两个思路，
1.直接写出函数史，直接得结果，但过于呆板，且有最多20个数据，太繁琐
2.计算模拟报数过程
*/
void CountOff(int n, int m, int out[])
{
    int in[n]; //模拟过程肯定要建立操作空间
    for (int i = 0; i < n; i++)
        in[i] = 1;               //你可能会问为什么，看下面
    int j = 0;                   //操作控制数
    int num = 1;                 //报数数
    for (int i = 1; i <= n; i++) //报n轮
    {
        while (1) //因for循环难以表达循环报数，直接while死循环，设置出口
        {
            if (in[j] != 0) //这里结合下面的代码就可以解释了，当一人出局时，将它赋为0，
                            //当轮到它时，跳过它。
            {
                in[j] = num; //报数
                num++;
            }
            if (in[j] == m) //报到m时
            {
                in[j] = 0;  //出局
                out[j] = i; //传给out它的位置，轮数
                num = 1;    //重置报数数
                break;      //跳出
            }
            j++;        //计数加一
            if (j == n) //越界行为，重置
                j = 0;
        }
    }
}