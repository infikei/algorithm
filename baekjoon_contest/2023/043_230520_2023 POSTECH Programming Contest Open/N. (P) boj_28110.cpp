// Solve 2023-05-20

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
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int a[3000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    int max_len = 0, ans = -1;
    for (int i = 1; i < n; i++) {
        int len = (a[i] - a[i - 1]) >> 1;
        if (max_len < len) {
            max_len = len;
            ans = a[i - 1] + len;
        }
    }

    cout << ans << '\n';

    return 0;
}
