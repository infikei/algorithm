// Solve 2025-11-11

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

// vector<int> nums;

// int get_n() {
//     nums = {1, 2, 2, 2, 2};
//     return size(nums);
// }

// ll get_query(int t) {
//     ll ret = 0;

//     for (int x : nums) {
//         ret += abs(x - t);
//     }

//     return ret;
// }

int main() {
    FASTIO;

    int n;
    cin >> n;
    // n = get_n(); cout << n << '\n';

    ll s;
    cout << "? " << 100000 << endl;
    cin >> s;
    // s = get_query(100000); cout << s << '\n';

    int low = 1;
    int high = 99999;
    int mn = 100000;

    while (low <= high) {
        int mid = (low + high) / 2;
        ll cur;
        cout << "? " << mid << endl;
        cin >> cur;
        // cur = get_query(mid); cout << cur << '\n';

        if ((ll) (100000 - mid) * n == s - cur) {
            mn = min(mn, mid);
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << "! " << mn << endl;
    return 0;
}
