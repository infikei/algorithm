// Solve 2023-12-05

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string s;
    cin >> s;

    int cup[5] = { 0, 1, 0, 0, 2 };

    for (char c : s) {
        if (c == 'A') swap(cup[1], cup[2]);
        else if (c == 'B') swap(cup[1], cup[3]);
        else if (c == 'C') swap(cup[1], cup[4]);
        else if (c == 'D') swap(cup[2], cup[3]);
        else if (c == 'E') swap(cup[2], cup[4]);
        else swap(cup[3], cup[4]);
    }

    for (int i = 1; i <= 4; i++) {
        if (cup[i] == 1) {
            cout << i << '\n';
        }
    }

    for (int i = 1; i <= 4; i++) {
        if (cup[i] == 2) {
            cout << i << '\n';
        }
    }

    return 0;
}
