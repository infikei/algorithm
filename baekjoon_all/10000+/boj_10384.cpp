// Solve 2026-03-13

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

int cnt[26];
string ans[4] = {
    "Not a pangram",
    "Pangram!",
    "Double pangram!!",
    "Triple pangram!!!"
};

int get_result() {
    for (int i = 3; i >= 1; i--) {
        bool flag = true;

        for (int j = 0; j < 26; j++) {
            if (cnt[j] < i) {
                flag = false;
                break;
            }
        }

        if (flag) {
            return i;
        }
    }

    return 0;
}

int main() {
    FASTIO;

    int t;
    cin >> t;
    cin.ignore();

    for (int ti = 1; ti <= t; ti++) {
        string s;
        getline(cin, s);
        memset(cnt, 0, sizeof(cnt));

        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                cnt[c - 'a']++;
            }
            else if (c >= 'A' && c <= 'Z') {
                cnt[c - 'A']++;
            }
        }

        cout << "Case " << ti << ": " << ans[get_result()] << '\n';
    }

    return 0;
}
