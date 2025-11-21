// Solve 2025-11-20

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

int recur(int i, int j, int cnt, string& s) {
    if (cnt >= 2) return 2;

    while (i < j) {
        if (s[i] != s[j]) {
            return min(recur(i, j - 1, cnt + 1, s), recur(i + 1, j, cnt + 1, s));
        }

        i++;
        j--;
    }

    return cnt;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        string s;
        cin >> s;
        cout << recur(0, size(s) - 1, 0, s) << '\n';
    }

    return 0;
}
