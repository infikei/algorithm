// Solve 2023-03-01

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
using pii = pair<int, int>;
using pi3 = pair<int, pii>;

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    priority_queue<pi3> pq_maxtop;
    pi3 k_val = { 0, { 0, 0 } };
    for (int i = 0; i < n; i++) {
        int x, a, b, c;
        cin >> x >> a >> b >> c;
        pq_maxtop.push({ a, { b, c } });
        if (x == k) {
            k_val = { a, { b, c } };
        }
    }

    int ans = 1;
    while (pq_maxtop.top() > k_val) {
        pq_maxtop.pop();
        ans++;
    }

    cout << ans << '\n';

    return 0;
}