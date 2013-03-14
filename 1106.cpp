#include <cstdio>

const int N(153);
int n;
double r, rr;
int x0, y0;
struct Point {
    int x, y;
    void move() { x -= x0; y -= y0; }
    bool in_circle() { return (x*x + y*y) <= rr; }
} p[N];

int main()
{
    int m, i, j;
    while (scanf("%d%d%lf", &(x0), &(y0), &r), r > 0) {
        rr = r * r;
        scanf("%d", &m);
        for (i = 0, n = 0; i < m; ++i) {
            scanf("%d%d", &(p[n].x), &(p[n].y));
            p[n].move();
            if (p[n].in_circle())
                ++n;
        }
        int a, b, c, d(0);
        for (i = 0; i < n; ++i) {
            a = b = c = 0;
            if (p[i].x == 0 && p[i].y == 0)
                continue;
            for (j = (i+1)%n; j != i; j = (j+1)%n) {
                m = p[i].x * p[j].y - p[i].y * p[j].x;
                if (m > 0)
                    ++a;
                else if (m < 0)
                    ++b;
                else
                    ++c;
            }
            if (a + c > d)
                d = a + c;
            if (b + c > d)
                d = b + c;
        }
        printf("%d\n", (n==0) ? 0 : (d+1));
    }
    return 0;
}
