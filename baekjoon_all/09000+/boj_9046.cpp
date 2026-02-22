// Solve 2026-02-21

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

int cnt[26];

int main() {
    FASTIO;

    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        memset(cnt, 0, sizeof(cnt));

        string s;
        getline(cin, s);

        for (char c : s) {
            if (c == ' ') continue;

            cnt[c - 'a']++;
        }

        int mx = 0;
        int mx_char = 'a';

        for (int i = 0; i < 26; i++) {
            if (cnt[i] > mx) {
                mx = cnt[i];
                mx_char = 'a' + i;
            }
            else if (cnt[i] == mx) {
                mx_char = '?';
            }
        }

        cout << (char) mx_char << '\n';
    }

    return 0;
}
