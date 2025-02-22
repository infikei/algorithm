// Solve 2025-02-21

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

// memo[0]은 현재까지 특정 동작을 유지했을 때의 최대 점수
// memo[1]은 동작을 최대 1번 변경했을 때의 최대 점수
int memo[2][3];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;

        int d = (c == 'H' ? 0 : c == 'P' ? 1 : 2);

        for (int j = 0; j < 3; j++) {
            memo[1][j] = max(memo[1][j], *max_element(memo[0], memo[0] + 3));
        }

        memo[0][d]++;
        memo[1][d]++;
    }

    int ans = *max_element(memo[1], memo[1] + 3);

    cout << ans << '\n';

    return 0;
}
