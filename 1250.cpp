#include <cstdio>
#include <cstring>

const int N(84);
char s[N];
char a[N];

int main()
{
    int n, m, i, j, k, w;
    while (scanf("%d", &n), n) {
        scanf("%s", s);
        for (i = 0, m = strlen(s), k = 0, w = 0; i < m; ++i) {
            for (j = 0; j < k; ++j) {
                if (a[j] == s[i]) {
                    a[j] = a[--k];
                    j = -1;
                    break;
                }
            }
            if (j != -1) {
                if (k >= n)
                    ++w;
                else
                    a[k++] = s[i];
            }
        }
        if (w == 0)
            printf("All customers tanned successfully.\n");
        else
            printf("%d customer(s) walked away.\n", w/2);
    }
    return 0;
}
