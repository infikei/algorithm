// Solve 2023-03-10

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

    int mine, ans = 0;
    cin >> mine;

    if (n > 1) {
        priority_queue<int> pq_maxtop;
        for (int i = 1; i < n; i++) {
            int x;
            cin >> x;
            pq_maxtop.push(x);
        }

        while (mine <= pq_maxtop.top()) {
            mine++;
            ans++;
            pq_maxtop.push(pq_maxtop.top() - 1);
            pq_maxtop.pop();
        }
    }

    cout << ans << '\n';

    return 0;
}