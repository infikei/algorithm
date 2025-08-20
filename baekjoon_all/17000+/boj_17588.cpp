// Solve 2025-08-17

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
    vector<int> missing_nums;
    int nxt_num = 1;

    while (n-- > 0) {
        int x;
        cin >> x;

        while (nxt_num < x) {
            missing_nums.push_back(nxt_num);
            nxt_num++;
        }

        nxt_num++;
    }

    if (missing_nums.empty()) {
        cout << "good job" << '\n';
        return 0;
    }

    for (int& num : missing_nums) {
        cout << num << '\n';
    }

    return 0;
}
