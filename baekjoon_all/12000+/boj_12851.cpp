// Solve 2023-01-06
// Update 2023-02-11

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

const int MAX_N = 100000;
int n, k, ans1[MAX_N + 1], ans2[MAX_N + 1];
queue<int> q;

void bfs() {
    ans2[n] = 1;
    if (n == k) return;

    q.push(n);
    int cur = 0;

    while (!q.empty()) {
        cur++;

        int i_end = SIZE(q);
        for (int i = 0; i < i_end; i++) {
            int now = q.front();
            q.pop();

            int next;

            next = now * 2;
            if (next <= MAX_N) {
                if (ans2[next] == 0) {
                    ans1[next] = cur;
                    ans2[next] = ans2[now];
                    q.push(next);
                }
                else if (ans1[next] == cur) {
                    ans2[next] += ans2[now];
                }
            }

            next = now + 1;
            if (next <= MAX_N) {
                if (ans2[next] == 0) {
                    ans1[next] = cur;
                    ans2[next] = ans2[now];
                    q.push(next);
                }
                else if (ans1[next] == cur) {
                    ans2[next] += ans2[now];
                }
            }

            next = now - 1;
            if (next >= 0) {
                if (ans2[next] == 0) {
                    ans1[next] = cur;
                    ans2[next] = ans2[now];
                    q.push(next);
                }
                else if (ans1[next] == cur) {
                    ans2[next] += ans2[now];
                }
            }
        }

        if (ans2[k] > 0) return;
    }
}

int main() {
    FASTIO;

    cin >> n >> k;

    bfs();

    cout << ans1[k] << '\n';
    cout << ans2[k] << '\n';

    return 0;
}