// Solve 2025-04-19

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

    int n, m_min, m_max, t, r;
    cin >> n >> m_min >> m_max >> t >> r;

    if (m_min + t > m_max) {
        cout << -1 << '\n';
        return 0;
    }

    int m = m_min;
    int cnt = 0;

    while (n > 0) {
        cnt++;

        if (m + t <= m_max) {
            m += t;
            n--;
        }
        else {
            m -= r;

            if (m < m_min) {
                m = m_min;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}
