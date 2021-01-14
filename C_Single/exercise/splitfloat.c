//本题要求实现一个拆分实数的整数与小数部分的简单函数。
//其中x是被拆分的实数（0≤x<10000），*intpart和*fracpart分别是将实数x拆分出来的整数部分与小数部分。
#include <stdio.h>

void splitfloat(float x, int *intpart, float *fracpart);

int main()
{
    float x, fracpart;
    int intpart;

    scanf("%f", &x);
    splitfloat(x, &intpart, &fracpart);
    printf("The integer part is %d\n", intpart);
    printf("The fractional part is %g\n", fracpart);

    return 0;
}
void splitfloat(float x, int *intpart, float *fracpart)
{
    *intpart = (int)x;
    *fracpart = x - *intpart;
}
