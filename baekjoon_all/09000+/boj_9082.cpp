// Solve 2025-11-18

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n;
string s[2];
int bomb[100];

int solution(int first) {
    memset(bomb, 0, sizeof bomb);
    bomb[0] = first;
    int ret = first;

    for (int i = 0; i < n; i++) {
        int cnt = bomb[i] + (i - 1 >= 0 ? bomb[i - 1] : 0);

        if (i + 1 < n) {
            if (s[1][i + 1] == '*' || cnt < s[0][i] - '0') {
                bomb[i + 1] = 1;
                cnt++;
                ret++;
            }
        }

        if (cnt != s[0][i] - '0') {
            return -1;
        }
    }

    return ret;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        cin >> n >> s[0] >> s[1];
        int mx = -1;

        if (s[1][0] == '*') {
            mx = solution(1);
        }
        else {
            mx = max(solution(0), solution(1));
        }

        cout << mx << '\n';
    }

    return 0;
}
