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

unordered_map<int, int> mp;
int s_prefix[100001];
int k_prefix[100001];

int main() {
    FASTIO;

    string s;
    cin >> s;

    mp[0] = 0;
    int mx = -1;
    int cur = 0;

    for (int i = 1; i <= size(s); i++) {
        s_prefix[i] = s_prefix[i - 1];
        k_prefix[i] = k_prefix[i - 1];

        if (s[i - 1] == 'S') {
            cur += 2;
            s_prefix[i]++;
        }
        else if (s[i - 1] == 'K') {
            cur--;
            k_prefix[i]++;
        }

        if (mp.find(cur) == mp.end()) {
            mp[cur] = i;
        }
        else {
            int prv_i = mp[cur];

            if (s_prefix[i] - s_prefix[prv_i] >= 1) {
                mx = max(mx, i - prv_i);
            }
        }
    }

    cout << mx << '\n';
    return 0;
}
