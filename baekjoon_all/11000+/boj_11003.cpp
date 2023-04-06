// Solve 2022-09-09
// Update 2023-04-05

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

int main() {
    FASTIO;

    int n, l;
    cin >> n >> l;

    deque<pii> dq;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        while (!dq.empty() && dq.front().second < i) {
            dq.pop_front();
        }

        while (!dq.empty() && dq.back().first >= x) {
            dq.pop_back();
        }

        dq.push_back({ x, i + l - 1 });

        cout << dq.front().first << ' ';
    }
    cout << '\n';

    return 0;
}
