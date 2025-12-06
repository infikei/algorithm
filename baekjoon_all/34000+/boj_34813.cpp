// Solve 2025-12-04

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main() {
    FASTIO;

    string s;
    cin >> s;

    if (s[0] == 'F') {
        cout << "Foundation" << '\n';
    }
    else if (s[0] == 'C') {
        cout << "Claves" << '\n';
    }
    else if (s[0] == 'V') {
        cout << "Veritas" << '\n';
    }
    else if (s[0] == 'E') {
        cout << "Exploration" << '\n';
    }

    return 0;
}
