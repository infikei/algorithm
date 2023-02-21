// Solve 2023-02-21

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int x, y;
    cin >> x >> y;

    int z = floor((double)y * 100 / x); // 부동소수점 문제를 피하기 위해 100을 먼저 곱하고 나누기

    if (z > 98) {
        cout << -1 << '\n';
    }
    else {
        int low = 0, high = x;
        while (low + 1 < high) {
            int mid = (low + high) / 2;

            int val = floor((double)(y + mid) * 100 / (x + mid)); // 부동소수점 문제를 피하기 위해 100을 먼저 곱하고 나누기
            if (val > z) {
                high = mid;
            }
            else {
                low = mid;
            }
        }

        cout << high << '\n';
    }

    return 0;
}