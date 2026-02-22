// Solve 2026-02-18

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

int get_score(double x, double y) {
    double r2 = x * x + y * y;

    for (int i = 3, score = 100; i <= 15; i += 3, score -= 20) {
        if (r2 <= i * i) {
            return score;
        }
    }

    return 0;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n = 0;
        int m = 0;

        for (int i = 0; i < 3; i++) {
            double x, y;
            cin >> x >> y;
            n += get_score(x, y);
        }

        for (int i = 0; i < 3; i++) {
            double x, y;
            cin >> x >> y;
            m += get_score(x, y);
        }

        cout << "SCORE: " << n << " to " << m << ", ";

        if (n > m) {
            cout << "PLAYER 1 WINS." << '\n';
        }
        else if (n < m) {
            cout << "PLAYER 2 WINS." << '\n';
        }
        else {
            cout << "TIE." << '\n';
        }
    }

    return 0;
}
