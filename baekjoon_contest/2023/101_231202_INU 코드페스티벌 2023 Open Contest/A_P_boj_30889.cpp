// Solve 2023-12-02

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

    vector<vector<bool>> reserved(10, vector<bool>(20, false));

    for (int i = 0; i < n; i++) {
        string seat;
        cin >> seat;

        reserved[seat[0] - 'A'][stoi(seat.substr(1)) - 1] = true;
    }

    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 20; c++) {
            cout << (reserved[r][c] ? 'o' : '.');
        }

        cout << '\n';
    }

    return 0;
}
