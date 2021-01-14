#include <stdio.h>

int reverse(int number);

int main()
{
    int n;

    scanf("%d", &n);
    printf("%d\n", reverse(n));

    return 0;
}

int reverse(int number)
{
    int ans = 0;
    while (number / 10 != 0)
    {
        int sun = number % 10;
        number /= 10;
        ans = ans * 10 + sun;
    }
    ans = ans * 10 + number;
    return ans;
}