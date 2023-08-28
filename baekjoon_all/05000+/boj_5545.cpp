// Solve 2023-05-06
// Update 2023-08-28

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

    int a, b, c;
    cin >> a >> b >> c;

    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        int di;
        cin >> di;

        pq.push(di);
    }

    int ans = c / a, ans1 = c, ans2 = a;

    for (int i = 0; i < n; i++) {
        ans1 += pq.top();
        ans2 += b;
        ans = max(ans, ans1 / ans2);

        pq.pop();
    }

    cout << ans << '\n';

    return 0;
}
