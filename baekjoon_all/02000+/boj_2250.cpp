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

int children[10001][2];
bool b[10001];
int num = 0;
int mn[10001];
int mx[10001];

void recur(int cur, int lv) {
    int l = children[cur][0];
    int r = children[cur][1];

    if (l != -1) {
        recur(l, lv + 1);
    }

    num++;
    mn[lv] = min(mn[lv], num);
    mx[lv] = max(mx[lv], num);

    if (r != -1) {
        recur(r, lv + 1);
    }
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int par, l, r;
        cin >> par >> l >> r;
        children[par][0] = l;
        children[par][1] = r;

        if (l != -1) b[l] = true;
        if (r != -1) b[r] = true;
    }

    int root = -1;

    for (int i = 1; i <= n; i++) {
        if (!b[i]) {
            root = i;
            break;
        }
    }

    memset(mn, 0x3f, sizeof mn);
    recur(root, 1);

    int mx_width = 0;
    int lv_of_mx_width = 0;

    for (int i = 1; i <= 10000; i++) {
        if (mn[i] > mx[i]) break;

        if (mx[i] - mn[i] + 1 > mx_width) {
            mx_width = mx[i] - mn[i] + 1;
            lv_of_mx_width = i;
        }
    }

    cout << lv_of_mx_width << ' ' << mx_width << '\n';
    return 0;
}
