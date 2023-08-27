// Solve 2023-07-01
// Update 2023-08-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int card[200][3];
int cnt[3][101];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int x;
            cin >> x;

            card[i][j] = x;
            cnt[j][x]++;
        }
    }

    for (int i = 0; i < n; i++) {
        int score = 0;

        for (int j = 0; j < 3; j++) {
            int x = card[i][j];

            if (cnt[j][x] == 1) {
                score += x;
            }
        }

        cout << score << '\n';
    }

    return 0;
}
