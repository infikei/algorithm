// Solve 2025-05-02

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

int memo[10001];

void init_memo(int m) {
    for (int i = 0; i <= m; i++) {
        memo[i] = 0;
    }
}

int main() {
    FASTIO;

    while (true) {
        int n, m;
        double m_d;
        cin >> n >> m_d;
        m = round(m_d * 100);

        if (n == 0 && m == 0) break;

        init_memo(m);

        for (int i = 0; i < n; i++) {
            int calorie, price;
            double price_d;
            cin >> calorie >> price_d;
            price = round(price_d * 100);

            for (int j = price; j <= m; j++) {
                memo[j] = max(memo[j], memo[j - price] + calorie);
            }
        }

        cout << memo[m] << '\n';
    }

    return 0;
}
