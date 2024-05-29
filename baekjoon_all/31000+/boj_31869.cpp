// Solve 2024-05-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

int main() {
    FASTIO;

    int n;
    cin >> n;

    unordered_map<string, pii> hs;

    for (int i = 0; i < n; i++) {
        string s;
        int w, d, p;
        cin >> s >> w >> d >> p;
        d += w * 7;
        hs[s] = { d, p };
    }

    bool checked[77] = { false };

    for (int i = 0; i < n; i++) {
        string s;
        int m;
        cin >> s >> m;

        pii cur = hs[s];

        if (cur.second <= m) {
            checked[cur.first] = true;
        }
    }

    int max_len = 0;
    int cur_len = 0;

    for (int i = 0; i < 77; i++) {
        if (checked[i]) {
            cur_len++;
            max_len = cur_len > max_len ? cur_len : max_len;
        }
        else {
            cur_len = 0;
        }
    }

    cout << max_len << '\n';

    return 0;
}
