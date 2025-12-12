// Solve 2025-12-10

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

int n;
double m, b;
double p[10];
double r[10];
double ans;

void recur(int depth, double cur_money, double cur_prob) {
    if (cur_money <= b) return;
    if (depth == n) {
        if (cur_money > 1) {
            ans += cur_prob;
        }
        return;
    }

    double m1 = cur_money * m;
    double m2 = cur_money - m1;

    recur(depth + 1, cur_money * (1 - m) + cur_money * m * r[depth], cur_prob * p[depth]);
    recur(depth + 1, cur_money * (1 - m), cur_prob * (1 - p[depth]));
}

int main() {
    FASTIO;

    cin >> n >> m >> b;
    m *= 0.01;
    b *= 0.01;

    for (int i = 0; i < n; i++) {
        cin >> p[i] >> r[i];
        p[i] *= 0.01;
    }

    recur(0, 1, 1);

    SETP(9);
    cout << ans * 100 << '\n';
    return 0;
}
