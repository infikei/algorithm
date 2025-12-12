// Solve 2025-12-11

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

int cnt[27];

string get_title(string& s) {
    string ret;
    stringstream ss(s);
    string w;

    while (getline(ss, w, ' ')) {
        if (w.empty()) continue;

        if ('A' <= w[0] && w[0] <= 'Z') {
            ret.push_back(w[0]);
        }
        else if ('a' <= w[0] && w[0] <= 'z') {
            ret.push_back(w[0] - 'a' + 'A');
        }
    }

    return ret;
}

bool write(string& s) {
    for (int i = 0; i < size(s); i++) {
        if (i >= 1 && s[i] == s[i - 1]) continue;

        if (s[i] == ' ') {
            if (--cnt[26] < 0) {
                return false;
            }
        }
        else if ('A' <= s[i] && s[i] <= 'Z') {
            if (--cnt[s[i] - 'A'] < 0) {
                return false;
            }
        }
        else if ('a' <= s[i] && s[i] <= 'z') {
            if (--cnt[s[i] - 'a'] < 0) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    FASTIO;

    string s;
    getline(cin, s);
    cin >> cnt[26];

    for (int i = 0; i < 26; i++) {
        cin >> cnt[i];
    }

    if (!write(s)) {
        cout << -1 << '\n';
        return 0;
    }

    string title = get_title(s);

    if (!write(title)) {
        cout << -1 << '\n';
        return 0;
    }

    cout << title << '\n';
    return 0;
}
