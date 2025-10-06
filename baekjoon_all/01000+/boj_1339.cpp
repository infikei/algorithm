// Solve 2024-03-24
// Update 2025-10-05

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

    int n;
    cin >> n;
    int coefficient[26] = {0};

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int p = 1;

        for (int i = 0; i < size(s); i++, p *= 10) {
            char ch = s[size(s) - 1 - i];
            coefficient[ch - 'A'] += p;
        }
    }

    sort(coefficient, coefficient + 26, greater<int>());
    int ans = 0;

    for (int i = 0; i < 9; i++) {
        ans += (9 - i) * coefficient[i];
    }

    cout << ans << '\n';
    return 0;
}
