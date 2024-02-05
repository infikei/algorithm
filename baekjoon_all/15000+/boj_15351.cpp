// Solve 2024-02-05

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        int score = 0;

        for (char c : s) {
            if (c >= 'A' && c <= 'Z') {
                score += c - 'A' + 1;
            }
        }

        if (score == 100) {
            cout << "PERFECT LIFE\n";
        }
        else {
            cout << score << '\n';
        }
    }

    return 0;
}
