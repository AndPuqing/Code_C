//实现一个对数组进行循环右移的简单函数：
//一个数组a中存有n（>0）个整数，将每个整数循环向右移m（≥0）个位置，
//即将a中的数据由（a0a​1⋯a​n−1）变换为（a​n−m⋯a​n−1a​0a​1⋯a​n−m−1 ​​ ）
//（最后m个数循环移至最前面的m个位置）。
//其中a[]是用户传入的数组；n是数组的大小；
//m是右移的位数。函数ArrayShift须将循环右移后的数组仍然存在a[]中。
#include <stdio.h>
#define MAXN 10

int ArrayShift(int a[], int n, int m);

int main()
{
    int a[MAXN], n, m;
    int i;

    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    ArrayShift(a, n, m);

    for (i = 0; i < n; i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}

int ArrayShift(int a[], int n, int m)
{
    if (m > n)
        m -= n;
    int b[n];
    for (int i = 0; i < n; i++)
        b[i] = a[i];
    for (int i = 0; i < n; i++)
    {
        int index = i + m;
        if (index > n - 1)
        {
            index -= n;
        }
        a[index] = b[i];
    }
}