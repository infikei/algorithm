// Solve 2026-03-08

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

string name[100];

bool can_concat(string& s1, string& s2) {
    for (int k = 1, ke = min(size(s1), size(s2)); k <= ke; k++) {
        if (s1.substr(size(s1) - k, k) == s2.substr(0, k)) {
            return true;
        }
    }

    return false;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> name[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (can_concat(name[i], name[j]) || can_concat(name[j], name[i])) {
                ans++;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
