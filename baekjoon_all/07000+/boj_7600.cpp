// Solve 2025-03-23

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

int main() {
    FASTIO;

    while (true) {
        string s;
        getline(cin, s);

        if (s == "#") break;

        int cnt[26] = { 0 };
        int ans = 0;

        for (char &c : s) {
            if (c >= 'a' && c <= 'z') {
                cnt[c - 'a']++;

                if (cnt[c - 'a'] == 1) {
                    ans++;
                }
            }
            else if (c >= 'A' && c <= 'Z') {
                cnt[c - 'A']++;

                if (cnt[c - 'A'] == 1) {
                    ans++;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
