// Solve 2023-08-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;

        vector<string> vec(n);

        for (string &s : vec) {
            cin >> s;
        }

        vector<bool> check(n, true);
        int cnt = n;
        int k = SIZE(vec[0]);

        for (int ki = 0; ki < k; ki++) {
            vector<int> rsp[3];

            for (int ni = 0; ni < n; ni++) {
                if (!check[ni]) continue;

                if (vec[ni][ki] == 'R') rsp[0].push_back(ni);
                else if (vec[ni][ki] == 'S') rsp[1].push_back(ni);
                else rsp[2].push_back(ni);
            }

            if (SIZE(rsp[0]) == 0) {
                if (SIZE(rsp[1]) > 0 && SIZE(rsp[2]) > 0) {
                    for (const int &ni : rsp[2]) {
                        check[ni] = false;
                        cnt--;
                    }
                }
            }
            else if (SIZE(rsp[1]) == 0) {
                if (SIZE(rsp[0]) > 0 && SIZE(rsp[2]) > 0) {
                    for (const int &ni : rsp[0]) {
                        check[ni] = false;
                        cnt--;
                    }
                }
            }
            else if (SIZE(rsp[2]) == 0) {
                if (SIZE(rsp[0]) > 0 && SIZE(rsp[1]) > 0) {
                    for (const int &ni : rsp[1]) {
                        check[ni] = false;
                        cnt--;
                    }
                }
            }

            if (cnt < 2) break;
        }

        if (cnt >= 2) {
            cout << 0 << '\n';
        }
        else {
            for (int ni = 0; ni < n; ni++) {
                if (check[ni]) {
                    cout << ni + 1 << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}
