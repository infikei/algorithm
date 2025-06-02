// Solve 2025-05-31

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

    string s;
    cin >> s;

    int cnt[26] = { 0 };

    for (char c : s) {
        cnt[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (cnt[i] >= (s.size() + 3) / 2) {
            cout << -1 << '\n';
            return 0;
        }
    }

    string ans;

    for (int i = 0; i < s.size(); i++) {
        int d = 0;

        while (cnt[d] == 0) d++;

        if (i >= (s.size() + 1) / 2) {
            int j = s.size() - 1 - i;

            if (ans[j] - 'a' == d) d++;

            while (cnt[d] == 0) d++;
        }

        ans.push_back('a' + d);
        cnt[d]--;
    }

    cout << ans << '\n';

    return 0;
}
