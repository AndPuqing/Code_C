//规定精度e，近似得到cos(x)的值
#include <stdio.h>
#include <math.h>

double funcos(double e, double x);

int main()
{
    double e, x;

    scanf("%lf %lf", &e, &x);
    printf("cos(%.2f) = %.6f\n", x, funcos(e, x));
    return 0;
}

double funcos(double e, double x)
{
    double i = 0;
    double po = 1;
    double ans = 0;
    double syn = 1;
    do
    {
        ans += syn * pow(x, i) / po;
        syn *= -1;
        i += 2;
        po = 1;
        for (int j = 1; j <= i; j++)
        {
            po *= j;
        }
    } while ((pow(x, i) / po) >= e); //这里注意当(pow(x, i) / po) >= e之后，跳出while，但要求还要进行一次运算
    ans += syn * pow(x, i) / po;
    return ans;
}