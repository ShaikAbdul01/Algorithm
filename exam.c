#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);

    int ar[n];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &ar[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", ar[j]);
        }
        printf("\n");
    }

    return 0;
}