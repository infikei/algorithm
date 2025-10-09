// Solve 2022-07-25
// Update 2025-10-09

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

int arr[1000];
int lis[1000]; // Longest Increasing Subsequence
int rlis[1000]; // Reversed LIS

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                lis[i] = max(lis[i], lis[j]);
            }
        }

        lis[i]++;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (arr[j] < arr[i]) {
                rlis[i] = max(rlis[i], rlis[j]);
            }
        }

        rlis[i]++;
    }

    int mx = 0;

    for (int i = 0; i < n; i++) {
        mx = max(mx, lis[i] + rlis[i] - 1);
    }

    cout << mx << '\n';
    return 0;
}
