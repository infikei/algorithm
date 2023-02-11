// Solve 2023-02-11

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

int a, b, parent[10000];

int d(int x) { return (x * 2) % 10000; }

int s(int x) { return (x == 0 ? 9999 : (x - 1)); }

int l(int x) { return x % 1000 * 10 + x / 1000; }

int r(int x) { return x % 10 * 1000 + x / 10; }

void bfs() {
    for (int i = 0; i < 10000; i++) {
        parent[i] = -1;
    }

    queue<int> q;
    q.push(a);
    parent[a] = a;

    while (!q.empty()) {
        int i_end = SIZE(q);
        for (int i = 0; i < i_end; i++) {
            int now = q.front();
            q.pop();

            int next;

            next = d(now);
            if (parent[next] == -1) {
                parent[next] = now;
                if (next == b) return;
                q.push(next);
            }

            next = s(now);
            if (parent[next] == -1) {
                parent[next] = now;
                if (next == b) return;
                q.push(next);
            }

            next = l(now);
            if (parent[next] == -1) {
                parent[next] = now;
                if (next == b) return;
                q.push(next);
            }

            next = r(now);
            if (parent[next] == -1) {
                parent[next] = now;
                if (next == b) return;
                q.push(next);
            }
        }
    }
}

void find_path() {
    string ans;

    int cur = b;
    while (cur != a) {
        int prev = parent[cur];
        char ch;
        if (d(prev) == cur) { ch = 'D'; }
        else if (s(prev) == cur) { ch = 'S'; }
        else if (l(prev) == cur) { ch = 'L'; }
        else { ch = 'R'; }
        ans = ch + ans;
        cur = prev;
    }

    cout << ans << '\n';
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        cin >> a >> b;

        bfs();

        find_path();
    }

    return 0;
}