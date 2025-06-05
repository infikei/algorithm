// Solve 2025-06-02

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

int main() {
    FASTIO;

    while (true) {
        int n;
        cin >> n;

        if (n == -1) break;

        int max_k = 1;

        for (int k = 2; k <= 7; k++) {
            int x = n;
            bool flag = true;

            for (int i = 0; i < k; i++) {
                x--;

                if (x < 0 || x % k != 0) {
                    flag = false;
                    break;
                }

                x = x / k * (k - 1);
            }

            if (flag && x % k != 0) flag = false;
            if (flag) max_k = max(max_k, k);
        }

        cout << n << " coconuts, ";

        if (max_k == 1) {
            cout << "no solution" << '\n';
        }
        else {
            cout << max_k << " people and 1 monkey" << '\n';
        }
    }

    return 0;
}
