// Solve 2025-11-04

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

int n;
int hist[300000];

bool valid(int len) {
    int cur = 0;

    for (int i = 0; i < n; i++) {
        if (hist[i] >= len) {
            cur++;

            if (cur == len) {
                return true;
            }
        }
        else {
            cur = 0;
        }
    }

    return false;
}

int main() {
    FASTIO;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> hist[i];
    }

    int low = 1;
    int high = 300000;
    int mx = 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (valid(mid)) {
            mx = max(mx, mid);
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << mx << '\n';
    return 0;
}
