// Solve 2024-02-18

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

    int alphabet_count[26] = { 0 };

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;

        alphabet_count[c - 'A']++;
    }

    char x;
    cin >> x;

    cout << alphabet_count[x - 'A'] << '\n';

    return 0;
}
