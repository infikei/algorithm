// Solve 2025-03-11

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

int arr[1000002];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;

        arr[s]++;
        arr[e + 1]--;
    }

    // imos algorithm
    for (int i = 1; i <= 1000001; i++) {
        arr[i] += arr[i - 1];
    }

    int q;
    cin >> q;

    while (q-- > 0) {
        int x;
        cin >> x;

        cout << arr[x] << '\n';
    }

    return 0;
}
