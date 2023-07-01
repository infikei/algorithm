// Solve 2023-07-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int card[200][4];
int cnt[3][101];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> card[i][j];
            cnt[j][card[i][j]]++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (cnt[j][card[i][j]] == 1) {
                card[i][3] += card[i][j];
            }
        }
        cout << card[i][3] << '\n';
    }

    return 0;
}
