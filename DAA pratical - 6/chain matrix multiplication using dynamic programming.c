#include <stdio.h>
#include <limits.h>

int main()
{
    int n, i, j, k, length;
    int p[10];
    int dp[10][10];

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions:\n");

    for(i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    /* Cost of multiplying one matrix is 0 */
    for(i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }

    for(length = 2; length <= n; length++)
    {
        for(i = 1; i <= n - length + 1; i++)
        {
            j = i + length - 1;

            dp[i][j] = INT_MAX;

            for(k = i; k < j; k++)
            {
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if(cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    printf("\nMinimum number of multiplications = %d\n",
           dp[1][n]);

    return 0;
}