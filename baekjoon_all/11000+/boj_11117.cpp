// Solve 2025-04-03

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

    int t;
    cin >> t;

    while (t-- > 0) {
        string cookie;
        int w;
        cin >> cookie >> w;

        int c_cnt[26] = { 0 };

        for (char &c : cookie) {
            c_cnt[c - 'A']++;
        }

        while (w-- > 0) {
            string word;
            cin >> word;

            int w_cnt[26] = { 0 };

            for (char &w : word) {
                w_cnt[w - 'A']++;
            }

            bool ans = true;

            for (int i = 0; i < 26; i++) {
                if (w_cnt[i] > c_cnt[i]) {
                    ans = false;
                    break;
                }
            }

            cout << (ans ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}
