// Solve 2023-11-26
// Update 2025-03-11

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

int fruits[200000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> fruits[i];
    }

    int max_len = 0;

    for (int i = 1; i <= 9; i++) {
        for (int j = i + 1; j <= 9; j++) {
            int cur_len = 0;

            for (int k = 0; k < n; k++) {
                if (fruits[k] == i || fruits[k] == j) {
                    cur_len++;
                }
                else {
                    max_len = max(max_len, cur_len);
                    cur_len = 0;
                }
            }

            max_len = max(max_len, cur_len);
        }
    }

    cout << max_len << '\n';

    return 0;
}
