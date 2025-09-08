// Solve 2023-02-06
// Update 2025-09-08

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

int arr[100000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cin >> x;
    int cnt = 0;
    unordered_set<int> hs;

    for (int i = 0; i < n; i++) {
        if (hs.find(x - arr[i]) != hs.end()) {
            cnt++;
        }

        hs.insert(arr[i]);
    }

    cout << cnt << '\n';
    return 0;
}
