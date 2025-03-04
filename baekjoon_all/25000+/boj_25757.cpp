// Solve 2024-04-17
// Update 2025-03-04

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

int main() {
    FASTIO;

    int n;
    char game_type;
    cin >> n >> game_type;

    unordered_set<string> hs;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        hs.insert(s);
    }

    if (game_type == 'Y') {
        cout << SIZE(hs) << '\n';
    }
    else if (game_type == 'F') {
        cout << SIZE(hs) / 2 << '\n';
    }
    else {
        cout << SIZE(hs) / 3 << '\n';
    }

    return 0;
}
