// Solve 2023-08-13
// Update 2025-09-05

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

    vector<int> vec(n);
    int vec_max = 0;

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        vec_max = max(vec_max, vec[i]);
    }

    for (int i = 0; i < n; i++) {
        while (vec[i] * 2 <= vec_max) {
            vec[i] *= 2;
        }
    }

    sort(vec.begin(), vec.end());
    int ans = vec.back() - vec[0];

    for (int i = 1; i < n; i++) {
        ans = min(ans, vec[i - 1] * 2 - vec[i]);
    }

    cout << ans << '\n';
    return 0;
}
