/*要求实现一个计算x^n（n≥1）的函数。
函数接口定义： double calc_pow(double x, int n);
函数calc_pow应返回x的n次幂的值。建议用递归实现。题目保证结果在双精度范围内。
*/

#include <stdio.h>

double calc_pow(double x, int n);

int main()
{
    double x;
    int n;

    scanf("%lf %d", &x, &n);
    printf("%.0f\n", calc_pow(x, n));

    return 0;
}

double calc_pow(double x, int n)
{
    if (n == 1)
    {
        return x;
    }
    return calc_pow(x, n - 1) * x;
}