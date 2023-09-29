// Solve 2023-09-29

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

    int cnt[26] = { 0 };

    for (char &c : s) {
        cnt[c - 'A'] = 1;
    }

    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0) {
            cout << (char)('A' + i) << '\n';
            break;
        }
    }

    return 0;
}
