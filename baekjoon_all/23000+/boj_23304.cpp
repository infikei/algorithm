// Solve 2025-11-24

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

bool is_palindrome(string& s, int len) {
    int i = 0;
    int j = len - 1;

    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }

        i++;
        j--;
    }

    return true;
}

bool is_akaraka(string& s) {
    int n = size(s);

    while (n > 1) {
        if (!is_palindrome(s, n)) {
            return false;
        }

        n /= 2;
    }

    return true;
}

int main() {
    FASTIO;

    string s;
    cin >> s;

    cout << (is_akaraka(s) ? "AKARAKA" : "IPSELENTI") << '\n';
    return 0;
}
