// Solve 2023-10-06

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
        string data;
        cin >> data;

        int error_cnt = 0;

        for (int i = 0, ie = SIZE(data); i < ie; i += 8) {
            int cnt = 0;

            for (int j = i, je = i + 7; j < je; j++) {
                if (data[j] == '1') cnt++;
            }

            if (cnt % 2 == 0 && data[i + 7] == '1' || cnt % 2 == 1 && data[i + 7] == '0') {
                error_cnt++;
            }
        }

        cout << error_cnt << '\n';
    }

    return 0;
}
