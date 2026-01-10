// Solve 2026-01-04

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

int n, k;
string words[50];
bool selected[26];
int mx;

bool check(string& w) {
    for (char c : w) {
        if (!selected[c - 'a']) {
            return false;
        }
    }

    return true;
}

void recur(int cur, int selected_cnt) {
    if (cur == 26) {
        if (selected_cnt != k) return;

        int readable = 0;

        for (int i = 0; i < n; i++) {
            if (check(words[i])) {
                readable++;
            }
        }

        mx = max(mx, readable);
        return;
    }

    if (selected_cnt < k && !selected[cur]) {
        selected[cur] = true;
        recur(cur + 1, selected_cnt + 1);
        selected[cur] = false;
    }

    recur(cur + 1, selected_cnt);
}

int main() {
    FASTIO;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        string w;
        cin >> w;

        sort(w.begin(), w.end());
        UNIQUE(w);

        words[i] = w;
    }

    if (k <= 4) {
        cout << 0 << '\n';
        return 0;
    }

    selected['a' - 'a'] = true;
    selected['n' - 'a'] = true;
    selected['t' - 'a'] = true;
    selected['i' - 'a'] = true;
    selected['c' - 'a'] = true;

    recur(0, 5);
    cout << mx << '\n';
    return 0;
}
