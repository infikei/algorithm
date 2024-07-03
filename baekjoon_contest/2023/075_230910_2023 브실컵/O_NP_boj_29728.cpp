// Solve 2023-09-12
// Update 2023-12-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<bool> is_prime(n + 1, true);

    is_prime[1] = false;

    for (int i = 2; i <= n; i++) {
        if (!is_prime[i]) continue;

        for (int j = i + i; j <= n; j += i) {
            is_prime[j] = false;
        }
    }

    int b_cnt = 1;
    int s_cnt = 0;

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            if (i == 3) {
                s_cnt++;
            }
            else {
                b_cnt--;
                s_cnt += 2;
            }
        }
        else {
            b_cnt++;
        }
    }

    cout << b_cnt << ' ' << s_cnt << '\n';

    return 0;
}
