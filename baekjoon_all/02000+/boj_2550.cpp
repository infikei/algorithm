// Solve 2025-02-19

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

int a[10001];
int a_inv[10001];
int b[10001];
int c[10001];
int memo_par[10001];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        a_inv[a[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        c[i] = a_inv[b[i]];
    }

    vector<int> memo;
    vector<int> memo_idx;

    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(memo.begin(), memo.end(), c[i]) - memo.begin();

        if (pos == size(memo)) {
            memo.push_back(c[i]);
            memo_idx.push_back(i);
        }
        else {
            memo[pos] = c[i];
            memo_idx[pos] = i;
        }

        if (pos == 0) {
            memo_par[i] = -1;
        }
        else {
            memo_par[i] = memo_idx[pos - 1];
        }
    }

    vector<int> ans;
    int pos = memo_idx.back();

    while (pos != -1) {
        ans.push_back(b[pos]);
        pos = memo_par[pos];
    }

    sort(ans.begin(), ans.end());

    cout << size(memo) << '\n';

    for (int &x : ans) {
        cout << x << ' ';
    }

    cout << '\n';

    return 0;
}
