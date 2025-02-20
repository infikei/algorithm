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

int arr[1000000];
int memo_par[1000000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> memo;
    vector<int> memo_idx;

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(memo.begin(), memo.end(), arr[i]) - memo.begin();

        if (pos == size(memo)) {
            memo.push_back(arr[i]);
            memo_idx.push_back(i);
        }
        else {
            memo[pos] = arr[i];
            memo_idx[pos] = i;
        }

        if (pos == 0) {
            memo_par[i] = -1;
        }
        else {
            memo_par[i] = memo_idx[pos - 1];
        }
    }

    cout << size(memo) << '\n';

    deque<int> path;
    int pos = memo_idx.back();

    while (pos != -1) {
        path.push_front(pos);
        pos = memo_par[pos];
    }

    for (auto &i : path) {
        cout << arr[i] << ' ';
    }

    cout << '\n';

    return 0;
}
