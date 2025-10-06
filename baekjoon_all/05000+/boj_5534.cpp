// Solve 2025-10-05

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

bool is_valid(string& s, string& t) {
    for (int start = 0; start < size(s); start++) {
        if (s[start] != t[0]) continue;

        for (int sep = 1; sep < size(s); sep++) {
            if (start + sep * ((int) size(t) - 1) >= size(s)) {
                continue;
            }

            bool flag = true;

            for (int i = 0; i < size(t); i++) {
                if (s[start + sep * i] != t[i]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    FASTIO;

    int n;
    string t;
    cin >> n >> t;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (is_valid(s, t)) {
            cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}
