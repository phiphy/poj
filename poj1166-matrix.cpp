/*
 * poj 1166 The Clocks
 */

#include <cstdio>

/* 
 * linear method
 
 assume A + Mx = 0, then x = M^{-1} * -A
*/
const int M[9][9] = {   // inverted matrix
    {3,2,3,2,2,1,3,1,0},
    {3,3,3,3,3,3,2,0,2},
    {3,2,3,1,2,2,0,1,3},
    {3,3,2,3,3,0,3,3,2},
    {3,2,3,2,1,2,3,2,3},
    {2,3,3,0,3,3,2,3,3},
    {3,1,0,2,2,1,3,2,3},
    {2,0,2,3,3,3,3,3,3},
    {0,1,3,1,2,2,3,2,3},
};
int main()
{
    int a[9], x[9] = {0};
    int i, j;
    for (i = 0; i < 9; ++i) {
        scanf("%d", a + i);
        a[i] = (4 - a[i]) % 4;
    }
    for (i = 0; i < 9; ++i)
        for (j = 0; j < 9; ++j)
            x[i] += a[j] * M[i][j];
    for (i = 0, j = 0; i < 9; ++i) {
        x[i] %= 4;
        if (x[i]) {
            printf("%s%d", j ? " " : "", i+1);
            while (--x[i])
                printf(" %d", i+1);
            j = 1;
        }
    }
    printf("\n");
    return 0;
}

/*
 * below is fixed depth dfs mathod

const int S[9] = {16, 14, 12, 10, 8, 6, 4, 2, 0};
const int move[9][9] = { {1, 1, 0, 1, 1, 0, 0, 0, 0}, 
    {1, 1, 1, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 0, 1, 1, 0, 0, 0}, 
    {1, 0, 0, 1, 0, 0, 1, 0, 0}, {0, 1, 0, 1, 1, 1, 0, 1, 0}, 
    {0, 0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 1, 1, 0, 1, 1, 0}, 
    {0, 0, 0, 0, 0, 0, 1, 1, 1}, {0, 0, 0, 0, 1, 1, 0, 1, 1} };
int b[9];

int g(const int z, const int *m)
{
    int r(0), i;
    for (i = 0; i < 9; ++i)
        r |= (((((z >> S[i]) & 3) + m[i]) % 4) << S[i]);
    return r;
}

bool f(const int z, const int n, int i, int *a)
{
    int zz;
    for (a[i] = a[i-1]; a[i] < 9; --b[a[i]++]) {
        if (++b[a[i]] > 3)
            continue;
        zz = g(z, move[a[i]]);
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
*/
