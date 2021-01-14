#include <stdio.h>
int xl, yd, xr, yu;
int though = 0, stay = 0;
int t = 0;
int isInit(int x, int y)
{
    if (x >= xl && x <= xr && y <= yu && y >= yd)
        return 1;
    else
        return 0;
}
void isStay(int p[2][t], int k, int t)
{
    int maxStay = 0;
    int staytmp = 0;
    int temp[t];
    int i;
    for (i = 0; i < t; i++)
    {
        int x = p[0][i], y = p[1][i];
        temp[i] = isInit(x, y);
    }
    for (i = 0; i < t; i++)
    {
        if (temp[i] == 1)
            staytmp++;
        else
        {
            if (staytmp > maxStay)
                maxStay = staytmp;
            staytmp = 0;
        }
        if (staytmp > maxStay)
            maxStay = staytmp;
    }
    if (maxStay >= k)
        stay++;
    if (maxStay > 0)
        though++;
}
int main()
{
    int n = 0, k = 0;
    scanf("%d %d %d %d %d %d %d", &n, &k, &t, &xl, &yd, &xr, &yu);
    int xy[2][t];
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < t; j++)
        {
            scanf("%d %d", &xy[0][j], &xy[1][j]);
        }
        isStay(xy, k, t);
    }
    printf("%d\n%d", though, stay);
    return 0;
}