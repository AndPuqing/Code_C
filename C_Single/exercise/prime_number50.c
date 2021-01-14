//生成50个素数
#include <stdio.h>

int main()
{
    int add = 0; //计数素数
    int num = 1; //校验数生成
    int a = 1;   //证伪布尔
    while (add < 50)
    {
        //校验素数
        for (int i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                a = 0;
                break;
            }
        }
        if (a == 1)
        {
            printf("prime number is:%d\n", num);
            add++;
        }
        a = 1;
        num++;
    }
}