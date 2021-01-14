#include <stdio.h>

int main()
{
    int n;
    int add = 0;
    scanf("%d", &n);
    for (int i = n; i <= n + 3; i++)
    {
        for (int j = n; j <= n + 3; j++)
        {
            for (int z = n; z <= n + 3; z++)
            {
                if (n != j && j != z && n != z)
                {
                    add++;
                    if (add % 6 != 0)
                    {
                        printf("%d ", i * 100 + j * 10 + z);
                    }
                    else
                    {
                        printf("%d\n", i * 100 + j * 10 + z);
                    }
                }
            }
        }
    }

    return 0;
}