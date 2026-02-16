// Solve 2026-02-15

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

string words[10000];

bool starts_with(string& s, string& w) {
    if (size(w) > size(s)) {
        return false;
    }

    for (int i = 0; i < size(w); i++) {
        if (s[i] != w[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    sort(words, words + n);
    int cnt = 0;

    for (int i = 0; i < m; i++) {
        string w;
        cin >> w;

        int idx = lower_bound(words, words + n, w) - words;

        if (idx < n && starts_with(words[idx], w)) {
            cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}
