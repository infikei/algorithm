// Solve 2023-02-18

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

const int MAX_VALUE = 500000;
int n, k;
bool visited[MAX_VALUE + 1][2];

int bfs() {
    if (n == k) {
        return 0;
    }

    queue<int> q;
    q.push(n);
    visited[n][0] = 0;
    int iter = 0, iter2 = 0;

    while (true) {
        iter++;
        k += iter;
        if (k > MAX_VALUE) {
            break;
        }
        iter2 = iter2 ^ 1;

        int i_end = SIZE(q);
        for (int i = 0; i < i_end; i++) {
            int now = q.front();
            q.pop();

            int next;

            next = now - 1;
            if (next >= 0 && !visited[next][iter2]) {
                visited[next][iter2] = true;
                q.push(next);
            }

            next = now + 1;
            if (next <= MAX_VALUE && !visited[next][iter2]) {
                visited[next][iter2] = true;
                q.push(next);
            }

            next = now * 2;
            if (next <= MAX_VALUE && !visited[next][iter2]) {
                visited[next][iter2] = true;
                q.push(next);
            }
        }

        if (visited[k][iter2]) {
            return iter;
        }
    }

    return -1;
}

int main() {
    FASTIO;

    cin >> n >> k;

    cout << bfs() << '\n';

    return 0;
}