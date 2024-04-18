// Solve 2024-04-17

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
