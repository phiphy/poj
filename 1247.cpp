#include <cstdio>

const int N(32);
int a[N];

int main()
{
    int n, i, j;
    while (scanf("%d", &n), n) {
        for (i = 0; i < n; ++i)
            scanf("%d", a + i);
        for (i = 0, j = n-1; i < j; ) {
            if (i+1 == j)
                break;
            if (a[0] <= a[n-1])
                a[0] += a[++i];
            else
                a[n-1] += a[--j];
        }
        if (i+1==j && a[0]==a[n-1])
            printf("Sam stops at position %d and Ella stops at position %d.\n", i+1, j+1);
        else
            printf("No equal partitioning.\n");
    }
    return 0;
}
