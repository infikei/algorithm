// Solve 2023-03-03

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

    int ans = 0;
    vector<int> ans2;

    for (int k = 1; k <= n; k++) {
        int now = 2;
        vector<int> now2 = { n, k };
        while (true) {
            int tmp = now2[now - 2] - now2[now - 1];
            if (tmp < 0) break;
            now2.push_back(tmp);
            now++;
        }

        if (now > ans) {
            ans = now;
            ans2 = now2;
        }
    }

    cout << ans << '\n';
    for (auto a : ans2) {
        cout << a << ' ';
    }
    cout << '\n';

    return 0;
}