// Solve 2026-02-15

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

void solution(char c1, int y1, char c2, int y2) {
    if (c1 == c2 && y1 == y2) {
        cout << 0 << ' ' << c1 << ' ' << y1 << '\n';
        return;
    }

    int x1 = c1 - 'A' + 1;
    int x2 = c2 - 'A' + 1;

    if ((x1 + y1) % 2 != (x2 + y2) % 2) {
        cout << "Impossible" << '\n';
        return;
    }

    if (x1 + y1 == x2 + y2 || x1 - y1 == x2 - y2) {
        cout << 1 << ' ' << c1 << ' ' << y1 << ' ' << c2 << ' ' << y2 << '\n';
        return;
    }

    for (int x3 = 1; x3 <= 8; x3++) {
        for (int y3 = 1; y3 <= 8; y3++) {
            if (x1 + y1 == x3 + y3 && x3 - y3 == x2 - y2) {
                char c3 = 'A' + (x3 - 1);
                cout << 2 << ' ' << c1 << ' ' << y1 << ' ' << c3 << ' ' << y3 << ' ' << c2 << ' ' << y2 << '\n';
                return;
            }

            if (x1 - y1 == x3 - y3 && x3 + y3 == x2 + y2) {
                char c3 = 'A' + (x3 - 1);
                cout << 2 << ' ' << c1 << ' ' << y1 << ' ' << c3 << ' ' << y3 << ' ' << c2 << ' ' << y2 << '\n';
                return;
            }
        }
    }
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        char c1, c2;
        int y1, y2;
        cin >> c1 >> y1 >> c2 >> y2;

        solution(c1, y1, c2, y2);
    }

    return 0;
}
