// Solve 2026-01-18

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

    int n, k;
    string s;
    cin >> n >> k >> s;

    int i = 0;
    int j = n - 1;

    while (i < j && k > 0) {
        while (i < j && s[i] == 'P') {
            i++;
        }

        while (i < j && s[j] == 'C') {
            j--;
        }

        if (i >= j) break;

        s[i] = 'P';
        s[j] = 'C';
        i++;
        j--;
        k--;
    }

    ll ans = 0;
    ll p_cnt = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'P') {
            p_cnt++;
        }
        else {
            ans += p_cnt * (p_cnt - 1) / 2;
        }
    }

    cout << ans << '\n';
    return 0;
}
