// Solve 2022-06-06
// Update 2023-03-01

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

    deque<int> dq;
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        int tmp = 0;
        while (dq.front() != x) {
            dq.push_back(dq.front());
            dq.pop_front();
            tmp++;
        }
        int tmp2 = SIZE(dq) - tmp;
        if (tmp > tmp2) {
            tmp = tmp2;
        }

        dq.pop_front();
        ans += tmp;
    }

    cout << ans << '\n';

    return 0;
}