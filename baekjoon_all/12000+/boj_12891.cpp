// Solve 2024-02-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int s, p;
    string dna;
    cin >> s >> p >> dna;

    string acgt = "ACGT";
    int min_cnt[26];

    for (int i = 0; i < 4; i++) {
        cin >> min_cnt[acgt[i] - 'A'];
    }

    int begin = 0;
    int end = 0;
    int cur_cnt[26] = { 0 };

    while (end < p) {
        cur_cnt[dna[end] - 'A']++;
        end++;
    }

    int ans = 0;
    bool flag = true;

    for (int i = 0; i < 4; i++) {
        if (cur_cnt[acgt[i] - 'A'] < min_cnt[acgt[i] - 'A']) {
            flag = false;
            break;
        }
    }

    if (flag) ans++;

    while (end < s) {
        cur_cnt[dna[begin] - 'A']--;
        cur_cnt[dna[end] - 'A']++;
        begin++;
        end++;

        flag = true;

        for (int i = 0; i < 4; i++) {
            if (cur_cnt[acgt[i] - 'A'] < min_cnt[acgt[i] - 'A']) {
                flag = false;
                break;
            }
        }

        if (flag) ans++;
    }

    cout << ans << '\n';

    return 0;
}
