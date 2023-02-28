// Solve 2022-08-01
// Update 2023-02-28

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

queue<int> q;
vector<int> ans;

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    ans.resize(n);

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < k; j++) {
            q.push(q.front());
            q.pop();
        }
        ans[i] = q.front();
        q.pop();
    }

    cout << '<' << ans[0];
    for (int i = 1; i < n; i++) {
        cout << ", " << ans[i];
    }
    cout << ">\n";

    return 0;
}