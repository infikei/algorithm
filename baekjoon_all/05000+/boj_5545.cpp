// Solve 2023-05-06

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

int main() {
    FASTIO;

    int n;
    cin >> n;

    int a, b, c;
    cin >> a >> b >> c;

    priority_queue<int> d;
    for (int i = 0; i < n; i++) {
        int di;
        cin >> di;
        d.push(di);
    }

    int ans = c / a, ans1 = c, ans2 = a;
    for (int i = 0; i < n; i++) {
        ans1 += d.top();
        ans2 += b;
        ans = max(ans, ans1 / ans2);

        d.pop();
    }

    cout << ans << '\n';

    return 0;
}
