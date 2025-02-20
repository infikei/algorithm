// Solve 2023-02-10
// Update 2025-02-19

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

pii a_to_b[100000];
int memo_par[100000];
int memo[100000];
int memo_idx[100000];
int memo_size = 0;
bool lis_included[100000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a_to_b[i].first >> a_to_b[i].second;
    }

    sort(a_to_b, a_to_b + n);

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(memo, memo + memo_size, a_to_b[i].second) - memo;

        if (pos == memo_size) {
            memo_size++;
        }

        memo[pos] = a_to_b[i].second;
        memo_idx[pos] = i;

        if (pos == 0) {
            memo_par[i] = -1;
        }
        else {
            memo_par[i] = memo_idx[pos - 1];
        }
    }

    cout << n - memo_size << '\n';

    int pos = memo_idx[memo_size - 1];

    while (pos != -1) {
        lis_included[pos] = true;
        pos = memo_par[pos];
    }

    for (int i = 0; i < n; i++) {
        if (!lis_included[i]) {
            cout << a_to_b[i].first << '\n';
        }
    }

    return 0;
}
