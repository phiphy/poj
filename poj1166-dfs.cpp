/*
 * poj 1166 The Clocks
 */

#include <cstdio>
#include <cstring>

const int S[9] = {16, 14, 12, 10, 8, 6, 4, 2, 0};
const int move[9][9] = { {1, 1, 0, 1, 1, 0, 0, 0, 0}, 
    {1, 1, 1, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 0, 1, 1, 0, 0, 0}, 
    {1, 0, 0, 1, 0, 0, 1, 0, 0}, {0, 1, 0, 1, 1, 1, 0, 1, 0}, 
    {0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 1, 1, 0, 1, 1, 0}, 
    {0, 0, 0, 0, 0, 0, 1, 1, 1}, {0, 0, 0, 0, 1, 1, 0, 1, 1} };
int b[9];

bool f(const int z, const int n, int i, int *a)
{
    int zz, j;
    for (a[i] = a[i-1]; a[i] < 9; --b[a[i]++]) {
        if (++b[a[i]] > 3)
            continue;
        for (zz = 0, j = 0; j < 9; ++j)
            zz |= (((((z >> S[j]) & 3) + move[a[i]][j]) % 4) << S[j]);
        if (zz==0 || (i<n && f(zz, n, i+1, a)))
            return true;
    }
    return false;
}

int main()
{
    int a[28] = {0};
    int i, j, z(0), n;
    for (i = 0; i < 9; ++i) {
        scanf("%d", &j);
        z |= (j << S[i]);
    }
    for (n = 1; n <= 27; ++n) {
        memset(b, 0, sizeof(b));
        if (f(z, n, 1, a)) {
            printf("%d", a[1]+1);
            for (i = 2; i <= n; ++i)
                printf(" %d", a[i]+1);
            printf("\n");
            break;
        }
    }
    return 0;
}
