/* poj 1157
 *
 * CAUTION: the boundry criteria
 *
 */

#include <cstdio>
#include <algorithm>

const int N(104), M(-10000);
int f, v;
int a[N][N];
int dp[N][N];

int main()
{
    int i, j;
    scanf("%d%d", &f, &v);
    for (i = 1; i <= f; ++i)
        for (j = 1; j <= v; ++j)
            scanf("%d", &(a[i][j]));

    for (i = 1; i <= v; ++i)
        dp[i][i-1] = M;
    for (j = 1; j <= v; ++j)
        dp[1][j] = std::max(dp[1][j-1], a[1][j]);
    for (i = 2; i <= f; ++i)
        for (j = i; j <= v; ++j)
            dp[i][j] = std::max(dp[i-1][j-1] + a[i][j], dp[i][j-1]);
    printf("%d\n", dp[f][v]);

    return 0;
}
