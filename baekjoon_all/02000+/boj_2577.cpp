// Solve 2022-06-03
// Update 2025-07-20

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

int main() {
    FASTIO;

    int a, b, c;
    cin >> a >> b >> c;

    int abc = a * b * c;
    int digit_cnt[10] = {0};

    while (abc > 0) {
        digit_cnt[abc % 10]++;
        abc /= 10;
    }

    for (int d : digit_cnt) {
        cout << d << '\n';
    }

    return 0;
}
