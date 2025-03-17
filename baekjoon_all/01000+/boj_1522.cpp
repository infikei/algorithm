// Solve 2025-03-15

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

    int b_cnt = 0;

    for (char &c : s) {
        if (c == 'b') {
            b_cnt++;
        }
    }

    int min_exchange_cnt = b_cnt;
    int cur_a_cnt = 0;

    for (int i = 0; i < b_cnt; i++) {
        if (s[i] == 'a') {
            cur_a_cnt++;
        }
    }

    for (int i = 0, j = b_cnt; i < s.size(); i++, j++) {
        if (j == s.size()) j = 0;

        min_exchange_cnt = min(min_exchange_cnt, cur_a_cnt);

        if (s[i] == 'a') cur_a_cnt--;
        if (s[j] == 'a') cur_a_cnt++;
    }

    cout << min_exchange_cnt << '\n';

    return 0;
}
