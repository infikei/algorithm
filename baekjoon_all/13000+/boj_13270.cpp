// Solve 2025-12-01

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

    vector<int> mn(n + 1, INF);
    vector<int> mx(n + 1, -INF);
    mn[0] = mx[0] = 0;

    int people = 2;
    int chicken = 1;

    while (people <= n) {
        for (int i = people; i <= n; i++) {
            mn[i] = min(mn[i], mn[i - people] + chicken);
            mx[i] = max(mx[i], mx[i - people] + chicken);
        }

        chicken += people;
        swap(people, chicken);
    }

    cout << mn[n] << ' ' << mx[n] << '\n';
    return 0;
}
