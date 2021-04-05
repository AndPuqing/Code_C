#include <stdio.h>
#include <stdlib.h>
int main()
{
    int scope;
    scanf("%d", &scanf);
    int *prime = (int *)malloc(scope * sizeof(int));
    prime[0] = 2;
    for (int i = 1; i <= scope; i++)
    {
        for (int i = 0; i < scope; i++)
        {
            if (i % prime[i] == 0)
            {
                break;
            }
        }
    }

    return 0;
}