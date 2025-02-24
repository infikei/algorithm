// Solve 2025-02-22

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

int arr[1000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> memo;

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(memo.begin(), memo.end(), arr[i]);

        if (it == memo.end()) {
            memo.push_back(arr[i]);
        }
        else {
            *it = arr[i];
        }
    }

    cout << size(memo) << '\n';

    return 0;
}
