// Solve 2024-02-04

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    queue<int> que;

    for (int i = 1; i <= n; i++) {
        que.push(i);
    }

    int idx = k - 1;

    while (SIZE(que) > 1) {
        if (++idx == k) {
            idx = 0;
            que.push(que.front());
            que.pop();
        }
        else {
            que.pop();
        }
    }

    cout << que.front() << '\n';

    return 0;
}
