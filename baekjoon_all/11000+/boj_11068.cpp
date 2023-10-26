// Solve 2023-10-25

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

        int ans = 0;

        for (int b = 2; b <= 64; b++) {
            vector<int> vec;
            int n2 = n;

            while (n2 > 0) {
                vec.push_back(n2 % b);
                n2 /= b;
            }

            bool flag = true;

            for (int i = 0, j = SIZE(vec) - 1; i < j; i++, j--) {
                if (vec[i] != vec[j]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                ans = 1;
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
