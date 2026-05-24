// Solve 2026-05-23

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

string digits = "22233344455566677778889999";

int main() {
    FASTIO;

    int n;
    cin >> n;
    string ans;

    while (n-- > 0) {
        string s;
        cin >> s;
        ans.push_back(digits[s[0] - 'a']);
    }

    cout << ans << '\n';
    return 0;
}
