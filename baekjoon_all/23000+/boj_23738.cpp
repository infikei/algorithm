// Solve 2025-10-19

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

string table[128];

int main() {
    FASTIO;

    table['A'] = "a";
    table['K'] = "k";
    table['M'] = "m";
    table['O'] = "o";
    table['T'] = "t";
    table['B'] = "v";
    table['E'] = "ye";
    table['H'] = "n";
    table['P'] = "r";
    table['C'] = "s";
    table['Y'] = "u";
    table['X'] = "h";

    string s;
    cin >> s;

    for (char c : s) {
        cout << table[c];
    }

    cout << '\n';
    return 0;
}
