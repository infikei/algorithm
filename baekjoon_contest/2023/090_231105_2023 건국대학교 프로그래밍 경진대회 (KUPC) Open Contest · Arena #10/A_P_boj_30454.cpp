// Solve 2023-11-05
// Update 2023-12-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, l;
    cin >> n >> l;

    int max_val = 0;
    int cnt_of_max_val = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int val = 0;
        char prev_c = '0';

        for (char &c : s) {
            if (prev_c == '0' && c == '1') {
                val++;
            }

            prev_c = c;
        }

        if (val > max_val) {
            max_val = val;
            cnt_of_max_val = 1;
        }
        else if (val == max_val) {
            cnt_of_max_val++;
        }
    }

    cout << max_val << ' ' << cnt_of_max_val << '\n';

    return 0;
}
