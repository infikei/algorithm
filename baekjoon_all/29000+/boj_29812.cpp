// Solve 2023-09-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, d, m;
    string s;
    cin >> n >> s >> d >> m;

    int ans = 0, cur = 0, cnt[3] = { 0 };

    for (char &c : s) {
        if (c == 'H' || c == 'Y' || c == 'U') {
            if (c == 'H') cnt[0]++;
            else if (c == 'Y') cnt[1]++;
            else cnt[2]++;

            ans += min(m + d, cur * d);
            cur = 0;
        }
        else {
            cur++;
        }
    }

    if (cur > 0) {
        ans += min(m + d, cur * d);
        cur = 0;
    }

    if (ans == 0) cout << "Nalmeok\n";
    else cout << ans << '\n';

    int ans2 = min({ cnt[0], cnt[1], cnt[2] });

    if (ans2 == 0) cout << "I love HanYang University\n";
    else cout << ans2 << '\n';

    return 0;
}
