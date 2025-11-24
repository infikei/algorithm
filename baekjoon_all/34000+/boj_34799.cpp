// Solve 2025-11-22

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

int cnt[26];

int main() {
    FASTIO;

    string s;
    ll n;
    cin >> s >> n;

    for (char c : s) {
        cnt[c - 'a']++;
    }

    ll q = n / 26;
    ll r = n % 26;
    ll ans = 0;

    for (int i = 0; i < 26; i++) {
        ans += q * cnt[i];
    }

    for (int i = 0, j = 'r' - 'a'; i < r; i++, j = (j + 1) % 26) {
        ans += cnt[j];
    }

    cout << ans << '\n';
    return 0;
}
