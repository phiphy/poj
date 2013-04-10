#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

const int N(11);
const int B[N] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000,
    100000000, 1000000000, 2000000000};
vector<int> v;

int main()
{
    int n, m, i, j, x, t, w;
    long long u;
    cin>>n;
    for (i = 2; i < N; ++i) {
        if (n < B[i]) {
            m = i;
            break;
        }
    }
    for (i = 0; i < m/2; ++i) {
        for (t = -B[i+1]+1, u = 10*(long long)n-B[i+1]+1; t < B[i+1]; ++t, ++u) {
            if (u % 11 == 0) {
                for (x = u / 11; t < B[i+1]; t += 11, ++x) {
                    if (t == (x% B[i+1] - 10*(x%B[i])))
                        v.push_back(x);
                }
                break;
            }
        }
    }
    for (; i < m; ++i) {
        if (n & 1)
            break;
        for (t = 1, x = (n+B[i])/2; x <= n; ++t, x += B[i]/2) {
            if (t == (x/B[i] - x/B[i+1]))
                v.push_back(x);
        }
    }
    sort(v.begin(), v.end());
    for (i = 1, j = 0; i < v.size(); ++i)
        if (v[i] == v[i-1])
            ++j;
    cout<<v.size()-j<<endl;
    for (i = 0; i < v.size(); ++i) {
        if (i!=0 && v[i]==v[i-1])
            continue;
        w = (v[i] < B[m-1]) ? (m - 2) : (m - 1);
        cout<<v[i]<<" + "<<setfill('0')<<setw(w)<<n-v[i]<<" = "<<n<<endl;
    }
    return 0;
}
