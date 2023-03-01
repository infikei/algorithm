// Solve 2023-03-01

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

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<string> graph(n);
    for (int i = 0; i < n; i++) {
        cin >> graph[i];
    }

    int ans = 0;
    for (int row = 0; row < n; row++) {
        int tmp = 0;
        for (int col = 0; col < n; col++) {
            if (graph[row][col] == '.') {
                tmp++;
            }
            else {
                if (tmp > 1) {
                    ans++;
                }
                tmp = 0;
            }
        }
        if (tmp > 1) {
            ans++;
        }
    }

    int ans2 = 0;
    for (int col = 0; col < n; col++) {
        int tmp = 0;
        for (int row = 0; row < n; row++) {
            if (graph[row][col] == '.') {
                tmp++;
            }
            else {
                if (tmp > 1) {
                    ans2++;
                }
                tmp = 0;
            }
        }
        if (tmp > 1) {
            ans2++;
        }
    }

    cout << ans << ' ' << ans2 << '\n';

    return 0;
}