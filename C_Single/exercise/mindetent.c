/*
这是ccf2020 09的第一题
完成计算最近三个点的输出
*/
#include <stdio.h>
#include <math.h>
int findmin(float *p, int length);
int main()
{
    int n, X, Y;
    int i;
    scanf("%d %d %d", &n, &X, &Y);
    int xy[2][n];
    float distance[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &xy[0][i], &xy[1][i]);
        distance[i] = sqrt((xy[0][i] - X) * (xy[0][i] - X) + (xy[1][i] - Y) * (xy[1][i] - Y)); //用sqrt是因为会越界
    }
    for (i = 0; i < 3; i++)
    {
        int point = findmin(distance, n);
        printf("%d\n", point + 1);
    }
    return 0;
}

int findmin(float *p, int length) //寻找最小值
{
    float min = 2000;
    int point = 0;
    int i;
    for (i = 0; i < length; i++)
    {
        if (p[i] < min && p[i] >= 0)
        {
            min = p[i];
            point = i;
        }
    }
    p[point] = 2000; //让最小值变大
    return point;
}