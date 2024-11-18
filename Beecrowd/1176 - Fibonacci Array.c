#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);

        if (n == 0)
            printf("Fib(0) = 0\n");
        else
        {
            n++;
            long long int f[n];
            f[0] = 0;
            f[1] = 1;

            
            for (int i = 2; i < n; i++)
                f[i] = f[i - 1] + f[i - 2];

            printf("Fib(%d) = %lld\n",n-1,f[n - 1]);
        }
    }
    return 0;
}
