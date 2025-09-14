// Solve 2025-09-13

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

vector<int> memo_a(1000);
vector<int> memo_b(1000);

int square_sum_of_all_digits(int x) {
    int ret = 0;

    while (x > 0) {
        int d = x % 10;
        x /= 10;
        ret += d * d;
    }

    return ret;
}

void cycle(int x, vector<int>& memo) {
    for (int& d : memo) {
        d = INF;
    }

    int i = 1;

    if (x < 1000) {
        memo[x] = i;
    }

    while (true) {
        x = square_sum_of_all_digits(x);
        i++;

        if (memo[x] != INF) {
            return;
        }

        memo[x] = i;
    }
}

int solution(int a, int b) {
    if (a == b) return 2;

    cycle(a, memo_a);
    cycle(b, memo_b);
    int ret = INF;

    for (int i = 1; i < 1000; i++) {
        ret = min(ret, memo_a[i] + memo_b[i]);
    }

    return (ret == INF ? 0 : ret);
}

int main() {
    FASTIO;

    while (true) {
        int a, b;
        cin >> a >> b;

        if (a == 0 && b == 0) break;

        int res = solution(a, b);
        cout << a << ' ' << b << ' ' << res << '\n';
    }

    return 0;
}
