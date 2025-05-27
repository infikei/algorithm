// Solve 2025-05-26

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

    int n;
    cin >> n;

    int cnt[4] = { 0 };

    while (n-- > 0) {
        string s;
        cin >> s;

        if (s == "1/4") cnt[1]++;
        else if (s == "1/2") cnt[2]++;
        else cnt[3]++;
    }

    int ans = 0;
    ans += cnt[3];
    cnt[1] = max(cnt[1] - cnt[3], 0);
    ans += (cnt[1] + cnt[2] * 2 + 3) / 4;

    cout << ans << '\n';
    return 0;
}
