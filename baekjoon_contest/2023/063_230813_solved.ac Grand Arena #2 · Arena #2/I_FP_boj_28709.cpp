// Solve 2023-08-14
// Update 2025-09-05

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

bool validate(string s) {
    if (count(s.begin(), s.end(), '*') >= 1) {
        int val = 0;

        for (int i = 0; s[i] != '*'; i++) {
            if (s[i] == ')') val--;
            else val++;

            if (val < 0) {
                return false;
            }
        }

        val = 0;

        for (int i = size(s) - 1; s[i] != '*'; i--) {
            if (s[i] == '(') val--;
            else val++;

            if (val < 0) {
                return false;
            }
        }

        return true;
    }
    else {
        if (size(s) % 2 == 1) {
            return false;
        }

        int cnt_open = count(s.begin(), s.end(), '(');
        int cnt_close = count(s.begin(), s.end(), ')');

        if (max(cnt_open, cnt_close) > size(s) / 2) {
            return false;
        }

        int val = 0;

        for (const char c : s) {
            if (c == '(') {
                val++;
            }
            else if (c == ')') {
                val--;
            }
            else if (cnt_open < size(s) / 2) {
                val++;
                cnt_open++;
            }
            else {
                val--;
            }

            if (val < 0) {
                return false;
            }
        }

        return val == 0;
    }
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        string s;
        cin >> s;
        cout << (validate(s) ? "YES" : "NO") << '\n';
    }

    return 0;
}
