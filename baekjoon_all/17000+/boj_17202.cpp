// Solve 2025-02-27

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

int main() {
    FASTIO;

    string a, b;
    cin >> a >> b;

    int arr[16];

    for (int i = 0; i < 8; i++) {
        arr[i * 2] = a[i] - '0';
        arr[i * 2 + 1] = b[i] - '0';
    }

    for (int i = 15; i >= 2; i--) {
        for (int j = 0; j < i; j++) {
            arr[j] = (arr[j] + arr[j + 1]) % 10;
        }
    }

    cout << arr[0] << arr[1] << '\n';

    return 0;
}
