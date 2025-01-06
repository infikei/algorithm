// Solve 2025-01-02

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

int main() {
    FASTIO;

    int m;
    cin >> m;

    vector<pii> lines;

    while (true) {
        int l, r;
        cin >> l >> r;

        if (l == 0 && r == 0) break;

        lines.emplace_back(l, r);
    }

    sort(all(lines));
    int cur = 0;
    int cnt = 0;

    for (int i = 0; i < size(lines); i++) {
        int nxt = cur;

        while (i < size(lines) && lines[i].first <= cur) {
            nxt = max(nxt, lines[i].second);
            i++;
        }

        if (nxt <= cur) break;

        i--;
        cur = nxt;
        cnt++;

        if (cur >= m) break;
    }

    if (cur >= m) {
        println(cnt);
    }
    else {
        println(0);
    }

    return 0;
}
