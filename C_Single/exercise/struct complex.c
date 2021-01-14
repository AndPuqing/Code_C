/*要求实现一个计算复数之积的简单函数。
函数接口定义：
struct complex multiply(struct complex x, struct complex y);
*/

#include <stdio.h>

struct complex
{
    int real;
    int imag;
};

struct complex multiply(struct complex x, struct complex y);

int main()
{
    struct complex product, x, y;

    scanf("%d%d%d%d", &x.real, &x.imag, &y.real, &y.imag);
    product = multiply(x, y);
    printf("(%d+%di) * (%d+%di) = %d + %di\n",
           x.real, x.imag, y.real, y.imag, product.real, product.imag);

    return 0;
}

struct complex multiply(struct complex x, struct complex y)
{
    struct complex re;

    re.real = x.real * y.real - x.imag * y.imag;
    re.imag = x.imag * y.real + y.imag * x.real;
    return re;
}