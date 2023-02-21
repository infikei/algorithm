// Solve 2023-02-21

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
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int arr[101];
queue<int> q;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int idx_b, idx_e, idx_m;
        cin >> idx_b >> idx_e >> idx_m;

        int idx = idx_b;
        for (; idx < idx_m; idx++) {
            q.push(arr[idx]);
        }
        int idx2 = idx_b;
        for (; idx <= idx_e; idx++) {
            arr[idx2] = arr[idx];
            idx2++;
        }
        for (; idx2 <= idx_e; idx2++) {
            arr[idx2] = q.front();
            q.pop();
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}