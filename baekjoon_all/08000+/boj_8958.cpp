// Solve 2022-06-03
// Update 2023-10-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        string oxox;
        cin >> oxox;

        int score = 0, cumulative = 0;

        for (char &ch : oxox) {
            if (ch == 'O') {
                score += ++cumulative;
            }
            else {
                cumulative = 0;
            }
        }

        cout << score << '\n';
    }

    return 0;
}
