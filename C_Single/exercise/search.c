//实现一个在数组中查找指定元素的简单函数。
//其中list[]是用户传入的数组；n（≥0）是list[]中元素的个数；x是待查找的元素。如果找到
//则函数search返回相应元素的最小下标（下标从0开始），否则返回−1。

#include <stdio.h>
#define MAXN 10

int search(int list[], int n, int x);

int main()
{
    int i, index, n, x;
    int a[MAXN];

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &x);
    index = search(a, n, x);
    if (index != -1)
        printf("index = %d\n", index);
    else
        printf("Not found\n");

    return 0;
}

int search(int list[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (list[i] == x)
        {
            return i;
        }
    }
    return -1;
}