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

    int cnt[26] = { 0 };

    for (char &ch : word) {
        if ('a' <= ch && ch <= 'z') {
            cnt[ch - 'a']++;
        }
        else {
            cnt[ch - 'A']++;
        }
    }

    int max_idx = max_element(cnt, cnt + 26) - cnt;
    int max_cnt = cnt[max_idx];

    for (int i = max_idx + 1; i < 26; i++) {
        if (cnt[i] == max_cnt) {
            max_idx = -1;
            break;
        }
    }

    if (max_idx == -1) {
        cout << "?\n";
    }
    else {
        cout << (char)('A' + max_idx) << '\n';
    }

    return 0;
}
