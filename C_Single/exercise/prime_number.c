//输出1-100的素数
#include <stdio.h>

int main()
{
    int answer = 1;                //证伪布尔
    for (int i = 1; i <= 100; i++) //1-100生成
    {
        for (int j = 2; j < i; j++) //除1和本身除法校验
        {
            if (i % j == 0)
            {
                answer = 0; //bool is false
                break;
            }
        }
        if (answer == 1)
        {
            printf("prime number is:%d\n", i);
        }
        answer = 1; //重置布尔
    }
    return 0;
}