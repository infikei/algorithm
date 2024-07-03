// Solve 2023-05-21

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
    priority_queue<int> pq_maxtop;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a & 1) {
            pq_maxtop.push(a);
        }
        else {
            ans += a;
        }
    }

    while (SIZE(pq_maxtop) >= 2) {
        ans += pq_maxtop.top();
        pq_maxtop.pop();
        ans += pq_maxtop.top();
        pq_maxtop.pop();
    }
    cout << ans << '\n';

    return 0;
}
