// Solve 2023-04-16
// Update 2025-02-26

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
    cin >> n;

    unordered_set<string> hs;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (SIZE(s) >= 6 && s.substr(SIZE(s) - 6, 6) == "Cheese") {
            hs.insert(s);
        }
    }

    if (SIZE(hs) >= 4) {
        cout << "yummy" << '\n';
    }
    else {
        cout << "sad" << '\n';
    }

    return 0;
}
