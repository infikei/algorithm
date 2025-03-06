// Solve 2025-03-05

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

ll count_no_repeat_nums(int len, int depth) {
    ll cnt = 1;

    for (int i = depth; i <= len; i++) {
        cnt *= (i == 1 ? 9 : (11 - i));
    }

    return cnt;
}

bool is_repeat_num(string num) {
    for (int i = 0; i < SIZE(num); i++) {
        for (int j = i + 1; j < SIZE(num); j++) {
            if (num[i] == num[j]) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    FASTIO;

    while (true) {
        int n;
        cin >> n;

        if (n == 0) break;

        int len = 0;
        ll cnt = 0;

        while (len <= 9) {
            len++;
            ll nxt_cnt = cnt + count_no_repeat_nums(len, 1);

            if (n <= nxt_cnt) break;

            cnt = nxt_cnt;
        }

        string ans(len, '0');
        ans[0] = '1';

        for (int depth = 2; depth <= len + 1; depth++) {
            while (depth >= 3 && is_repeat_num(ans.substr(0, depth - 1))) {
                ans[depth - 2]++;
            }

            while (true) {
                ll nxt_cnt = cnt + count_no_repeat_nums(len, depth);

                if (n <= nxt_cnt) break;

                ans[depth - 2]++;

                while (depth >= 3 && is_repeat_num(ans.substr(0, depth - 1))) {
                    ans[depth - 2]++;
                }

                cnt = nxt_cnt;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
