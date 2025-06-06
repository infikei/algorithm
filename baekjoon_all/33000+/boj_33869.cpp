// Solve 2025-06-06

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

bool used[26];

int main() {
    FASTIO;

    string w, s;
    cin >> w >> s;

    string key;

    for (char c : w) {
        if (used[c - 'A']) continue;

        used[c - 'A'] = true;
        key.push_back(c);
    }

    for (int i = 0; i < 26; i++) {
        if (used[i]) continue;

        key.push_back('A' + i);
    }

    string encryption;

    for (char c : s) {
        encryption.push_back(key[c - 'A']);
    }

    cout << encryption << '\n';

    return 0;
}
