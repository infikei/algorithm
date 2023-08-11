// Solve 2023-08-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

unordered_map<string, int> hs;

int main() {
    FASTIO;

    int n;
    cin >> n;

    int cnt = 0, cnt2 = 0;

    for (int i = 0; i < n; i++) {
        int idx, res, m, t, lang, len;
        string handle;

        cin >> idx >> handle >> res >> m >> t >> lang >> len;

        if (handle == "megalusion" || hs[handle] == -1) continue;

        hs[handle]++;

        if (res == 4) {
            cnt++;
            cnt2 += hs[handle];
            hs[handle] = -1;
        }
    }

    SETPRECISION(12);

    if (cnt2 == 0) cout << 0 << '\n';
    else cout << cnt * 100.0 / cnt2 << '\n';

    return 0;
}
