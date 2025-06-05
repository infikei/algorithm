// Solve 2025-06-03

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

int timetable[100000];
int like_or_hate[100001];

int main() {
    FASTIO;

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    for (int i = 0; i < n; i++) {
        cin >> timetable[i];
    }

    for (int i = 0; i < a; i++) {
        int x;
        cin >> x;
        like_or_hate[x] = 1;
    }

    for (int i = 0; i < b; i++) {
        int x;
        cin >> x;
        like_or_hate[x] = -1;
    }

    int ans = 0;
    int cur = 0;

    for (int i = 0; i < n; i++) {
        int lh = like_or_hate[timetable[i]];

        if (lh == 1) {
            if (cur <= -3) {
                ans += cur;
            }

            cur = max(cur, 0) + 1;
        }
        else if (lh == -1) {
            if (cur >= 3) {
                ans += cur;
            }

            cur = min(cur, 0) - 1;
        }
        else {
            if (cur >= 3 || cur <= -3) {
                ans += cur;
            }

            cur = 0;
        }
    }

    if (cur >= 3 || cur <= -3) {
        ans += cur;
    }

    cout << ans << '\n';

    return 0;
}
