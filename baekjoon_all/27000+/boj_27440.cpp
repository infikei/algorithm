// Solve 2023-02-09

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

ll n;
int ans;
queue<ll> bfs_q;
unordered_map<ll, bool> visited;

void bfs() {
    if (n == 1) {
        return;
    }

    bfs_q.push(n);

    while (!bfs_q.empty()) {
        ans++;
        int i_end = SIZE(bfs_q);
        for (int i = 0; i < i_end; i++) {
            ll cur = bfs_q.front();
            bfs_q.pop();

            bool is_multiple_of_3 = (cur % 3 == 0);
            bool is_multiple_of_2 = (cur % 2 == 0);

            if (is_multiple_of_3) {
                ll next = cur / 3;
                if (next == 1) {
                    return;
                }
                if (visited.find(next) == visited.end()) {
                    visited[next] = true;
                    bfs_q.push(next);
                }
            }
            if (is_multiple_of_2) {
                ll next = cur / 2;
                if (next == 1) {
                    return;
                }
                if (visited.find(next) == visited.end()) {
                    visited[next] = true;
                    bfs_q.push(next);
                }
            }
            if (!is_multiple_of_3 || !is_multiple_of_2) {
                ll next = cur - 1;
                if (next == 1) {
                    return;
                }
                if (visited.find(next) == visited.end()) {
                    visited[next] = true;
                    bfs_q.push(next);
                }
            }
        }
    }
}

int main() {
    FASTIO;

    cin >> n;

    bfs();

    cout << ans << '\n';

    return 0;
}