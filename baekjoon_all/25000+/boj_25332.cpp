// Solve 2026-02-22

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

int a[200001];
unordered_map<int, int> mp;

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        int b;
        cin >> b;
        a[i] -= b;
    }

    ll cnt = 0;
    mp[0]++;

    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];

        cnt += mp[a[i]];
        mp[a[i]]++;
    }

    cout << cnt << '\n';
    return 0;
}
