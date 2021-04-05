//ASCII转char
#include <stdio.h>

// #include <stdio.h>
// void main()
// {
//     int a;
//     while (~scanf("%d", &a)) //“~”意为取反，下面有对此的解释。
//                              //也可写为while(scanf("%d",&a)==1)。这两种写法都有EOF的功效。
//         printf("%c", a);
// }
//
int main()
{
    int a[100];
    int i;
    while ((scanf("%d", &a[i])) != EOF) //读入输入数据
    {
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        printf("%c", a[j]);
    }
    return 0;
}