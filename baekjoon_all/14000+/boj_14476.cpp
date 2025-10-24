// Solve 2025-10-21

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

int arr[1000000];
int prefix[1000000];
int suffix[1000000];

int get_gcd(int a, int b) {
    while (b > 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    prefix[0] = arr[0];

    for (int i = 1; i < n; i++) {
        prefix[i] = get_gcd(arr[i], prefix[i - 1]);
    }

    suffix[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = get_gcd(arr[i], suffix[i + 1]);
    }

    int mx_gcd = -1;
    int num_removed = -1;

    for (int i = 0; i < n; i++) {
        int gcd;

        if (i == 0) {
            gcd = suffix[1];
        }
        else if (i == n - 1) {
            gcd = prefix[n - 2];
        }
        else {
            gcd = get_gcd(prefix[i - 1], suffix[i + 1]);
        }

        if (arr[i] % gcd == 0) continue;

        if (gcd > mx_gcd) {
            mx_gcd = gcd;
            num_removed = arr[i];
        }
    }

    if (mx_gcd == -1) {
        cout << -1 << '\n';
    }
    else {
        cout << mx_gcd << ' ' << num_removed << '\n';
    }

    return 0;
}
