// Solve 2022-06-06
// Update 2023-10-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    deque<int> dque;

    for (int i = 1; i <= n; i++) {
        dque.push_back(i);
    }

    int ans = 0;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        int cnt = 0;

        while (dque.front() != x) {
            dque.push_back(dque.front());
            dque.pop_front();
            cnt++;
        }

        ans += min(cnt, SIZE(dque) - cnt);

        dque.pop_front();
    }

    cout << ans << '\n';

    return 0;
}
