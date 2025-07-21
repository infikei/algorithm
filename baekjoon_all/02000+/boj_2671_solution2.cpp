// Solve 2023-04-27
// Update 2025-07-20

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

bool is_submarine(string& s) {
    int i = 0;

    while (i < size(s)) {
        if (s[i] == '0') {
            if (i + 1 == size(s) || s[i + 1] != '1') return false;

            i += 2;
            continue;
        }

        if (i + 1 == size(s) || s[i + 1] != '0') return false;
        if (i + 2 == size(s) || s[i + 2] != '0') return false;

        i += 3;

        while (i < size(s) && s[i] == '0') i++;
        if (i == size(s)) return false;
        while (i < size(s) && s[i] == '1') i++;
        if (i == size(s)) continue;

        if (i + 1 < size(s) && s[i + 1] == '1') {
            i += 2;
            continue;
        }

        if (i + 1 < size(s) && s[i + 1] == '0' && s[i - 2] == '1') {
            i--;
            continue;
        }

        return false;
    }

    return true;
}

int main() {
    FASTIO;

    string s;
    cin >> s;
    cout << (is_submarine(s) ? "SUBMARINE" : "NOISE") << '\n';
    return 0;
}
