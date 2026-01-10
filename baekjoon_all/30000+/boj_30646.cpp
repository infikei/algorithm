// Solve 2026-01-08

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

int arr[200001];
ll prefix[200001];
map<int, int> mp;

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        prefix[i] += prefix[i - 1] + arr[i];
    }

    ll mx = 0;
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        ll s;

        if (mp.find(arr[i]) == mp.end()) {
            mp[arr[i]] = i;
            s = arr[i];
        }
        else {
            int prv = mp[arr[i]];
            s = prefix[i] - prefix[prv - 1];
        }

        if (s > mx) {
            mx = s;
            cnt = 1;
        }
        else if (s == mx) {
            cnt++;
        }
    }

    cout << mx << ' ' << cnt << '\n';
    return 0;
}
