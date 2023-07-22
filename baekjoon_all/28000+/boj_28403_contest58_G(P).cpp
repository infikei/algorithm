// Solve 2023-07-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int cnt[1000001];

int calc_cnt(int a, int b) {
    return cnt[b] - cnt[a - 1];
}

int main() {
    FASTIO;

    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cnt[i + 1] = cnt[i];
        if (s[i] == 'S') cnt[i + 1]++;
    }

    for (int i = 1; i <= n; i++) {
        int ans = 0;
        int pos = 1, cnt_to_find = i;

        while (cnt_to_find > 0) {
            int next_pos = pos + cnt_to_find;
            if (next_pos - 1 > n) break;
            ans++;
            cnt_to_find -= calc_cnt(pos, next_pos - 1);
            pos = next_pos;
        }

        cout << ans << ' ';
    }
    cout << '\n';

    return 0;
}
