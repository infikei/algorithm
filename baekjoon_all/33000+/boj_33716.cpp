// Solve 2025-04-02

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

const int INF = 10000000;
const int MAX_K = 25;

int memo[MAX_K + 1];
int tmp[MAX_K + 1];
int memo_by_alphabet[26][MAX_K + 1];

void init_memo(int k) {
    memo[0] = 0;

    for (int i = 1; i <= k; i++) {
        memo[i] = INF;
    }
}

void init_memo_by_alphabet(int k) {
    for (int i = 0; i < 26; i++) {
        memo_by_alphabet[i][0] = INF;

        for (int j = 1; j <= k; j++) {
            memo_by_alphabet[i][j] = INF;
        }
    }
}

void init_tmp(int k) {
    for (int i = 0; i <= k; i++) {
        tmp[i] = INF;
    }
}

int main() {
    FASTIO;

    int n, k;
    string s;
    cin >> n >> k >> s;

    k = min(k, MAX_K);

    init_memo(k);
    init_memo_by_alphabet(k);

    for (int i = 0; i < n; i++) {
        int c = s[i] - 'A';

        if (c == 23) {
            for (int j = 0; j <= k; j++) {
                memo[j]++;
            }

            continue;
        }

        init_tmp(k);

        for (int j = 1; j <= k; j++) {
            tmp[j] = memo_by_alphabet[c][j];
            memo_by_alphabet[c][j] = min(memo_by_alphabet[c][j], memo[j - 1]);
            tmp[j] = min(tmp[j], memo[j] + 1);
        }

        tmp[0] = memo[0] + 1;
        swap(memo, tmp);
    }

    int ans = INF;

    for (int i = 0; i <= k; i++) {
        ans = min(ans, memo[i]);
    }

    cout << ans << '\n';

    return 0;
}
