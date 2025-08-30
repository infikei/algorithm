// Solve 2025-08-27

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

bool is_valid(string& s) {
    for (int len = 1; len * 2 <= size(s); len++) {
        string p1 = s.substr(size(s) - len * 2, len);
        string p2 = s.substr(size(s) - len, len);

        if (p1 == p2) {
            return false;
        }
    }

    return true;
}

bool recur(string& cur, int n) {
    if (size(cur) == n) {
        return true;
    }

    for (char c = '1'; c <= '3'; c++) {
        cur.push_back(c);

        if (is_valid(cur) && recur(cur, n)) {
            return true;
        }

        cur.pop_back();
    }

    return false;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    string cur = "";
    recur(cur, n);
    cout << cur << '\n';
    return 0;
}
