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

    int n, m;
    cin >> n >> m;

    stack<int> stck;
    int ans = 0;
    for (int row = 0; row < n; row++) {
        int x;
        cin >> x;
        stck.push(x);

        for (int col = 1; col < m; col++) {
            cin >> x;
            if (x != stck.top()) {
                stck.push(x);
            }
        }

        while (!stck.empty()) {
            if (stck.top() == 0) {
                stck.pop();
                continue;
            }

            int tmp = 0;
            while (!stck.empty() && stck.top() != 0) {
                tmp++;
                stck.pop();
            }
            ans += tmp / 2 + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
