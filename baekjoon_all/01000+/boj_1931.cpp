// Solve 2022-07-16
// Update 2023-07-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Meet{
    int s, e;
    Meet(int ns = 0, int ne = 0) : s(ns), e(ne) {}
    bool operator<(const Meet &rhs) const {
        if (e != rhs.e) return e < rhs.e;
        return s < rhs.s;
    }
};

Meet meet[100000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        meet[i] = { s, e };
    }

    sort(meet, meet + n);

    int ans = 0, t = 0;
    for (int i = 0; i < n; i++) {
        if (meet[i].s < t) continue;
        ans++;
        t = meet[i].e;
    }

    cout << ans << '\n';

    return 0;
}
