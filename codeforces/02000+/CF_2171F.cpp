// Solve 2025-11-21

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

    int mx = 0;

    for (int i = 1, j = n; i < n; i++, j--) {
        mx = max(mx, a[j]);

        if (mx == i) {
            cout << "No" << '\n';
            return;
        }
    }

    cout << "Yes" << '\n';
    vector<int> v;
    int mn = a[1];

    for (int i = 2; i <= n; i++) {
        while (!v.empty() && v.back() < a[i]) {
            cout << v.back() << ' ' << a[i] << '\n';
            v.pop_back();
        }

        if (mn < a[i]) {
            cout << mn << ' ' << a[i] << '\n';
        }
        else {
            v.push_back(mn);
            mn = a[i];
        }
    }
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
