// Solve 2023-09-22

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

    string ans = to_string(n);
    int ans_len = SIZE(ans);

    if (ans_len >= 4) {
        for (ll c = 1, ce = sqrt(n); c <= ce; c++) {
            string cc = to_string(c);

            if (n % c == 0) {
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

                    if (val == n) {
                        string aa = to_string(a);
                        string bb = to_string(b);

                        if (c == 1) {
                            int res_len = SIZE(aa) + SIZE(bb) + 1;

                            if (res_len < ans_len) {
                                ans_len = res_len;
                                ans = aa + " " + bb + " ^";
                            }
                        }
                        else {
                            int res_len = SIZE(cc) + SIZE(aa) + SIZE(bb) + 2;

                            if (res_len < ans_len) {
                                ans_len = res_len;
                                ans = cc + " " + aa + " " + bb + " ^ *";
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
