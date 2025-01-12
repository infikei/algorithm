// Solve 2025-01-09

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

int prefix_sum[1001];

int main() {
    FASTIO;

    string s;
    cin >> s;

    int n = size(s);

    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + s[i - 1] - '0';
    }

    int ans = -1;

    for (int len = n / 2 * 2; len > 0; len -= 2) {
        int half_len = len / 2;

        for (int i = len; i <= n; i++) {
            int left_sum = prefix_sum[i - half_len] - prefix_sum[i - len];
            int right_sum = prefix_sum[i] - prefix_sum[i - half_len];

            if (left_sum == right_sum) {
                ans = len;
                break;
            }
        }

        if (ans != -1) break;
    }

    println(ans);

    return 0;
}
