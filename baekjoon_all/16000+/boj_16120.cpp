// Solve 2025-03-09

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

    string s;
    cin >> s;

    string stck;

    for (char c : s) {
        stck.push_back(c);

        if (stck.size() >= 4 && stck.substr(stck.size() - 4, 4) == "PPAP") {
            stck.pop_back();
            stck.pop_back();
            stck.pop_back();
        }
    }

    if (stck.size() == 1 && stck[0] == 'P') {
        cout << "PPAP" << '\n';
    }
    else {
        cout << "NP" << '\n';
    }

    return 0;
}
