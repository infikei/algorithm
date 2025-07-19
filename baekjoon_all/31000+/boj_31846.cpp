// Solve 2025-07-18

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

string s;

int solution(int l, int r) {
    int max_score = 0;

    for (int mid = l; mid < r; mid++) {
        int pl = mid;
        int pr = mid + 1;
        int score = 0;

        while (pl >= l && pr <= r) {
            if (s[pl] == s[pr]) {
                score++;
            }

            pl--;
            pr++;
        }

        max_score = max(max_score, score);
    }

    return max_score;
}

int main() {
    FASTIO;

    int n, q;
    cin >> n >> s >> q;

    while (q-- > 0) {
        int l, r;
        cin >> l >> r;
        cout << solution(l - 1, r - 1) << '\n';
    }

    return 0;
}
