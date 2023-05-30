// Solve 2023-05-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

char graph[50][50];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    int ans1 = 0, ans2 = 0;

    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'X') {
                flag = false;
            }
        }
        if (flag) ans1++;
    }

    for (int j = 0; j < m; j++) {
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (graph[i][j] == 'X') {
                flag = false;
                break;
            }
        }
        if (flag) ans2++;
    }

    cout << max(ans1, ans2) << '\n';

    return 0;
}
