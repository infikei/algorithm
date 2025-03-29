// Solve 2024-04-14
// Update 2025-03-28

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    FASTIO;

    int n, k;
    string s;
    cin >> n >> k >> s;

    string ans;

    for (char &c : s) {
        while (!ans.empty() && ans.back() < c && k > 0) {
            k--;
            ans.pop_back();
        }

        ans.push_back(c);
    }

    while (k > 0) {
        k--;
        ans.pop_back();
    }

    cout << ans << '\n';

    return 0;
}
