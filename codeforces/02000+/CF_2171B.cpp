// Solve 2025-11-20

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

int a[200010];

void solution() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (a[1] == -1 && a[n] == -1) {
        a[1] = 0;
        a[n] = 0;
    }
    else if (a[1] == -1) {
        a[1] = a[n];
    }
    else if (a[n] == -1) {
        a[n] = a[1];
    }

    cout << abs(a[n] - a[1]) << '\n';

    for (int i = 1; i <= n; i++) {
        cout << (a[i] == -1 ? 0 : a[i]) << ' ';
    }

    cout << '\n';
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        solution();
    }

    return 0;
}
