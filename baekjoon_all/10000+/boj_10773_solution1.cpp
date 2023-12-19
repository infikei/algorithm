// Solve 2022-06-05
// Update 2023-12-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int k;
    cin >> k;

    stack<int> stck;

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;

        if (x == 0) stck.pop();
        else stck.push(x);
    }

    int ans = 0;

    while (!stck.empty()) {
        ans += stck.top();
        stck.pop();
    }

    cout << ans << '\n';

    return 0;
}
