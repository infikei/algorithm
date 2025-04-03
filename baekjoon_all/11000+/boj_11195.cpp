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

    string s;
    cin >> s;

    int cnt[26] = { 0 };

    for (char &c : s) {
        cnt[c - 'a']++;
    }

    int odd_cnt = 0;

    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 1) {
            odd_cnt++;
        }
    }

    cout << max(0, odd_cnt - 1) << '\n';

    return 0;
}
