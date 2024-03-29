// Solve 2022-06-05
// Update 2024-02-02

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

    queue<int> que;

    for (int i = 1; i <= n; i++) {
        que.push(i);
    }

    for (int i = 1; i < n; i++) {
        que.pop();
        que.push(que.front());
        que.pop();
    }

    cout << que.front() << '\n';

    return 0;
}
