// Solve 2026-05-05

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

void solution(int a, int b) {
    if (a < 0 || a > 1000 || b < 0 || b > 4000) {
        cout << "INPUT ERROR!" << '\n';
        return;
    }

    for (int i = 0; i <= a; i++) {
        if (i * 4 + (a - i) * 2 == b) {
            cout << i << ' ' << a - i << '\n';
            return;
        }
    }

    cout << 0 << '\n';
}

int main() {
    FASTIO;

    while (true) {
        int a, b;
        cin >> a >> b;

        if (a == 0 && b == 0) break;

        solution(a, b);
    }

    return 0;
}
