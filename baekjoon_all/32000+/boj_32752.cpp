// Solve 2025-05-08

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

int arr[100001];

int main() {
    FASTIO;

    int n, l, r;
    cin >> n >> l >> r;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    sort(arr + l, arr + (r + 1));

    for (int i = 2; i <= n; i++) {
        if (arr[i - 1] > arr[i]) {
            cout << 0 << '\n';
            return 0;
        }
    }

    cout << 1 << '\n';

    return 0;
}
