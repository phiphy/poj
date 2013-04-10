#include <cstdio>
#include <cmath>

const int N(10002);
int a[N];

int main()
{
    int n, k, i, maxv(0);
    double l;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; ++i) {
        scanf("%lf", &l);
        a[i] = round(l * 100);
        if (a[i] > maxv)
            maxv = a[i];
    }
    int lv(1), rv(maxv), midv, sum;
    while (lv <= rv) {
        midv = (lv + rv) / 2;
        for (sum = 0, i = 0; i < n; ++i)
            sum += a[i] / midv;
        if (sum < k)
            rv = midv - 1;
        else
            lv = midv + 1;
    }
    printf("%.2f\n", rv / 100.0);   // first I use %.2lf, but WA, so use %.2f
    return 0;
}
