// Solve 2023-01-01
// Update 2024-12-12

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

int file[501];
int file_sum[501];
int memo[501][501];

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int k;
        cin >> k;

        for (int i = 1; i <= k; i++) {
            cin >> file[i];
        }

        for (int i = 1; i <= k; i++) {
            file_sum[i] = file_sum[i - 1] + file[i];
        }

        for (int len = 2; len <= k; len++) {
            for (int left = 1; left <= k + 1 - len; left++) {
                int right = left + len - 1;

                memo[left][right] = memo[left + 1][right];

                for (int mid = left + 2; mid <= right; mid++) {
                    memo[left][right] = min(memo[left][right], memo[left][mid - 1] + memo[mid][right]);
                }

                memo[left][right] += file_sum[right] - file_sum[left - 1];
            }
        }

        println(memo[1][k]);
    }

    return 0;
}
