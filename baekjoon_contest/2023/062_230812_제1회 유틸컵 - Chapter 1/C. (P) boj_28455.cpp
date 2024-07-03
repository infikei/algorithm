// Solve 2023-08-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int> > pq_mintop;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        pq_mintop.push(x);

        if (SIZE(pq_mintop) > 42) {
            pq_mintop.pop();
        }
    }

    int ans = 0, ans2 = 0;

    while (!pq_mintop.empty()) {
        int x = pq_mintop.top();
        pq_mintop.pop();

        ans += x;

        if (x >= 250) ans2 += 5;
        else if (x >= 200) ans2 += 4;
        else if (x >= 140) ans2 += 3;
        else if (x >= 100) ans2 += 2;
        else if (x >= 60) ans2 += 1;
    }

    cout << ans << ' ' << ans2 << '\n';

    return 0;
}
