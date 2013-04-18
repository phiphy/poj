/*
 * poj 1091
 *
 * 数论题，本质是求有多少组数的最大公约数是1。
 * 因此求出所有组合数，然后减去含有一个质因子的情况，加上有两个质因子的情况，
 * 减去有三个质因子的情况，依此类推……
 */
#include <cstdio>
#include <cmath>

typedef long long i64;

i64 pow64(i64 x, int y)
{
    i64 r(1);
    while (y--)
        r *= x;
    return r;
}

int main()
{
    int p[10];
    int n, m, i, j, k(0), x, y, z;
    scanf("%d%d", &n, &m);
    i64 r = pow64(m, n);
    for (i = 2, j = m, z = sqrt(m); i <= z; ++i) {
        if (j%i == 0) {
            p[k++] = i;
            j /= i;
            while (j%i == 0)
                j /= i;
        }
    }
    if (j != 1)
        p[k++] = j;
    for (i = 1, z = 1<<k; i < z; ++i) {     // 2^k - 1 combinations
        for (x = 1, y = 0, j = 0; j < k; ++j) {
            if (i & (1 << j)) {
                x *= p[j];
                y = 1 - y;
            }
        }
        if (y)
            r -= pow64(m/x, n);
        else
            r += pow64(m/x, n);
    }
    printf("%lld\n", r);
    return 0;
}
