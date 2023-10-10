// Solve 2022-06-05
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

    string word;
    cin >> word;

    int ans[26];
    fill_n(ans, 26, -1);

    for (int i = 0, ie = SIZE(word); i < ie; i++) {
        if (ans[word[i] - 'a'] == -1)
            ans[word[i] - 'a'] = i;
    }

    for (int i = 0; i < 26; i++) {
        cout << ans[i] << ' ';
    }

    cout << '\n';

    return 0;
}
