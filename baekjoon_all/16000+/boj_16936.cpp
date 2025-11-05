// Solve 2025-11-05

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

struct Num{
    ll v;
    int p2;
    int p3;

    Num(ll v) : v(v) {
        ll tmp = v;
        p2 = 0;
        p3 = 0;

        while (tmp % 2 == 0) {
            tmp /= 2;
            p2++;
        }

        while (tmp % 3 == 0) {
            tmp /= 3;
            p3++;
        }
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;
    vector<Num> nums;

    for (int i = 0; i < n; i++) {
        ll v;
        cin >> v;
        nums.emplace_back(v);
    }

    auto cmp = [](Num& a, Num& b) {
        if (a.p3 != b.p3) return a.p3 > b.p3;
        return a.p2 < b.p2;
    };

    sort(nums.begin(), nums.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << nums[i].v << ' ';
    }

    cout << '\n';
    return 0;
}
