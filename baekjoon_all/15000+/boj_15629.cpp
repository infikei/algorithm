// Solve 2024-05-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    unordered_map<string, int> hs;
    hs["botswana"] = 0;
    hs["ethiopia"] = 50;
    hs["kenya"] = 50;
    // hs["namibia"] = 0;
    hs["south-africa"] = 0;
    hs["tanzania"] = 50;
    // hs["zambia"] = 50;
    // hs["zimbabwe"] = 30;

    int n;
    cin >> n;

    string countries[8];
    int ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> countries[i];

        if (countries[i] == "namibia") {
            bool flag = false;

            for (int j = 0; j < i; j++) {
                if (countries[j] == "south-africa") {
                    flag = true;
                    break;
                }
            }

            ans += flag ? 40 : 140;
        }
        else if (countries[i] == "zambia") {
            ans += 50;

            if (i >= 1 && countries[i - 1] == "zimbabwe") {
                ans -= 30;
            }
        }
        else if (countries[i] == "zimbabwe") {
            ans += 30;

            if (i >= 1 && countries[i - 1] == "zambia") {
                ans -= 30;
            }
        }
        else {
            ans += hs[countries[i]];
        }
    }

    cout << ans << '\n';

    return 0;
}
