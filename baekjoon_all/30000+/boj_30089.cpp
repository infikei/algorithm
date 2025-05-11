// Solve 2025-05-11

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

bool is_palindrome(string s) {
    int i = 0;
    int j = s.size() - 1;

    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }

        i++;
        j--;
    }

    return true;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        string s;
        cin >> s;

        string rs = s;
        reverse(rs.begin(), rs.end());

        for (int i = s.size(); i >= 1; i--) {
            if (is_palindrome(s.substr(s.size() - i, i))) {
                cout << s.substr(0, s.size() - i) + rs << '\n';
                break;
            }
        }
    }

    return 0;
}
