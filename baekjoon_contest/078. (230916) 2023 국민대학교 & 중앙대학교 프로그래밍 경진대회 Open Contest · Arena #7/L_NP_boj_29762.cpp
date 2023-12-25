// Solve 2023-09-22
// Update 2023-10-05

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    ll n;
    cin >> n;

    string ans_str = to_string(n);
    int ans_len = SIZE(ans_str);

    if (ans_len >= 4) {
        for (ll c = 1, c_end = sqrt(n); c <= c_end; c++) {
            if (n % c != 0) continue;

            string c_str = to_string(c);
            ll a = 1;

            while (true) {
                a++;
                ll val = c * a * a;
                int b = 2;

                if (val > n) break;

                while (val < n) {
                    val *= a;
                    b++;
                }

                if (val != n) continue;

                string a_str = to_string(a);
                string b_str = to_string(b);

                if (c == 1) {
                    int res_len = SIZE(a_str) + SIZE(b_str) + 1;

                    if (res_len < ans_len) {
                        ans_len = res_len;
                        ans_str = a_str + " " + b_str + " ^";
                    }
                }
                else {
                    int res_len = SIZE(c_str) + SIZE(a_str) + SIZE(b_str) + 2;

                    if (res_len < ans_len) {
                        ans_len = res_len;
                        ans_str = c_str + " " + a_str + " " + b_str + " ^ *";
                    }
                }
            }
        }
    }

    cout << ans_str << '\n';

    return 0;
}
