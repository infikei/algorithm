// Solve 2022-09-13
// Update 2023-07-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int arr[2000];
bool dp[2000][2000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        int s = i, e = i;

        while (s >= 0 && e < n) {
            if (arr[s] != arr[e]) {
                break;
            }

            dp[s][e] = true;
            s--;
            e++;
        }
    }

    for (int i = 0; i < n; i++) {
        int s = i, e = i + 1;

        while (s >= 0 && e < n) {
            if (arr[s] != arr[e]) {
                break;
            }

            dp[s][e] = true;
            s--;
            e++;
        }
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;

        cout << dp[s - 1][e - 1] << '\n';
    }

    return 0;
}
