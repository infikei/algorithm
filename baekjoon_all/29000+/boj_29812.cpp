// Solve 2023-09-20
// Update 2024-07-12

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d, m;
    string s;
    cin >> n >> s >> d >> m;

    int ans = 0, cur = 0, cnt[3] = { 0 };

    for (char &c : s) {
        if (c == 'H') {
            cnt[0]++;
            ans += min(m + d, cur * d);
            cur = 0;
        }
        else if (c == 'Y') {
            cnt[1]++;
            ans += min(m + d, cur * d);
            cur = 0;
        }
        else if (c == 'U') {
            cnt[2]++;
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

    int hyu_cnt = min({ cnt[0], cnt[1], cnt[2] });

    if (hyu_cnt == 0) cout << "I love HanYang University\n";
    else cout << hyu_cnt << '\n';

    return 0;
}
