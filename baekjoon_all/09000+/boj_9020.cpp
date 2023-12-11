// Solve 2023-12-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    vector<bool> is_prime(10001, true);
    is_prime[1] = false;

    for (int i = 2; i < 10001; i++) {
        if (!is_prime[i]) continue;

        for (int j = i + i; j < 10001; j += i) {
            is_prime[j] = false;
        }
    }

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;

        int k = n / 2;

        while (k > 1) {
            int kk = n - k;

            if (is_prime[k] && is_prime[kk]) {
                cout << k << ' ' << kk << '\n';
                break;
            }

            k--;
        }
    }

    return 0;
}
