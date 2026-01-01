// Solve 2025-12-25

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

int get_count(string& s) {
    int ret = 0;

    for (char c : s) {
        if (c == 'w') {
            ret++;
        }
    }

    return ret;
}

int main() {
    FASTIO;

    int n;
    string s, t;
    cin >> n >> s >> t;

    if (s == t) {
        cout << "Good" << '\n';
        return 0;
    }

    int a = get_count(s);
    int b = get_count(t);

    if (a > b) {
        cout << "Oryang" << '\n';
    }
    else if (a < b) {
        cout << "Manners maketh man" << '\n';
    }
    else {
        cout << "Its fine" << '\n';
    }

    return 0;
}
