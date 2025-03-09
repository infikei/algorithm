// Solve 2022-07-29
// Update 2025-03-09

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int prefix_sum[200001][26];

int main() {
    FASTIO;

    string s;
    int q;
    cin >> s >> q;

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 26; j++) {
            prefix_sum[i + 1][j] = prefix_sum[i][j];
        }

        prefix_sum[i + 1][s[i] - 'a']++;
    }

    while (q-- > 0) {
        char alpha;
        int left, right;
        cin >> alpha >> left >> right;

        cout << prefix_sum[right + 1][alpha - 'a'] - prefix_sum[left][alpha - 'a'] << '\n';
    }

    return 0;
}
