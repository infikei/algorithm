// Solve 2022-10-27
// Update 2023-02-26

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

const int MAX_SIZE = 101;
bool graph[MAX_SIZE][MAX_SIZE];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        for (int dx = 0; dx < 10; dx++) {
            for (int dy = 0; dy < 10; dy++) {
                graph[x + dx][y + dy] = true;
            }
        }
    }

    int ans = 0;
    for (int nx = 1; nx < MAX_SIZE; nx++) {
        for (int ny = 1; ny < MAX_SIZE; ny++) {
            if (graph[nx][ny]) {
                ans++;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}