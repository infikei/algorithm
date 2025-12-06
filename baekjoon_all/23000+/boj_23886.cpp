// Solve 2025-12-02

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

bool is_alpsoo(string s) {
    int n = size(s);

    if (s[0] >= s[1] || s[n - 2] <= s[n - 1]) {
        return false;
    }

    for (int i = 1; i + 1 < size(s); i++) {
        int a = s[i - 1] - '0';
        int b = s[i] - '0';
        int c = s[i + 1] - '0';

        if (a == b || b == c) return false;
        if (a < b && b < c && b * 2 != a + c) return false;
        if (a > b && b > c && b * 2 != a + c) return false;
    }

    return true;
}

int main() {
    FASTIO;

    string s;
    cin >> s;

    cout << (is_alpsoo(s) ? "ALPSOO" : "NON ALPSOO") << '\n';
    return 0;
}
