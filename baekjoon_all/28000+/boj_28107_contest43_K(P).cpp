// Solve 2023-05-20

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

priority_queue<int, vector<int>, greater<int> > pq_mintop[200001];
int ans[100001];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;

        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            pq_mintop[a].push(i);
        }
    }

    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;

        if (pq_mintop[b].empty()) continue;
        int p = pq_mintop[b].top();
        pq_mintop[b].pop();
        ans[p]++;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}
