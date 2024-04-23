// Solve 2024-04-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, new_score, p;
    cin >> n >> new_score >> p;

    int scores[50];

    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    int idx = 0;

    while (idx < n) {
        if (new_score > scores[idx]) {
            break;
        }
        else if (new_score == scores[idx]) {
            int j = idx;

            while (j < n && new_score == scores[j]) {
                j++;
            }

            if (j == p) {
                idx = p;
            }

            break;
        }

        idx++;
    }

    cout << (idx == p ? -1 : idx + 1) << '\n';

    return 0;
}
