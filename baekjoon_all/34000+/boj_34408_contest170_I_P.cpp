// Solve 2025-09-21

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

int main() {
    FASTIO;

    string s, t;
    cin >> s >> t;

    int s_cnt[26] = {0};
    int t_cnt[26] = {0};

    for (char c : s) {
        s_cnt[c - 'A']++;
    }

    for (char c : t) {
        t_cnt[c - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
        if (s_cnt[i] < t_cnt[i]) {
            cout << "NEED FIX" << '\n';
            return 0;
        }
    }

    cout << "OK" << '\n';
    return 0;
}
