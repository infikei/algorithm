// Solve 2022-06-07
// Update 2023-10-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    int ans = 0;

    for (int ni = 0; ni < n; ni++) {
        string word;
        cin >> word;

        bool group_word = true;
        bool visited[26] = { false };
        char prev_ch = word[0];

        for (int i = 1, ie = SIZE(word); i < ie; i++) {
            char now_ch = word[i];

            if (prev_ch != now_ch) {
                if (visited[now_ch - 'a']) {
                    group_word = false;
                    break;
                }
                else {
                    visited[prev_ch - 'a'] = true;
                    prev_ch = now_ch;
                }
            }
        }

        if (group_word) ans++;
    }

    cout << ans << '\n';

    return 0;
}
