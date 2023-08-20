// Solve 2023-08-18

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<string> vec(n);

    for (string &s : vec) {
        cin >> s;
        sort(s.begin(), s.end());
    }

    sort(vec.begin(), vec.end());

    int cnt[26] = { 0 };

    for (int i = 0; i < k; i++) {
        for (const char c : vec[i]) {
            cnt[c - 'A']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        char c = 'A' + i;

        for (int j = 0, je = cnt[i]; j < je; j++) {
            cout << c;
        }
    }

    cout << '\n';

    return 0;
}
