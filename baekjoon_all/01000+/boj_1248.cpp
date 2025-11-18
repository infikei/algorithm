// Solve 2025-11-18

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
char s[10][10];
int arr[10];

bool check(int idx) {
    int prefix_sum = 0;

    for (int i = idx; i >= 0; i--) {
        prefix_sum += arr[i];

        if (prefix_sum > 0 && s[i][idx] != '+') return false;
        if (prefix_sum < 0 && s[i][idx] != '-') return false;
        if (prefix_sum == 0 && s[i][idx] != '0') return false;
    }

    return true;
}

bool recur(int idx) {
    if (idx == n) return true;

    for (int d = -10; d <= 10; d++) {
        arr[idx] = d;

        if (check(idx) && recur(idx + 1)) {
            return true;
        }
    }

    return false;
}

int main() {
    FASTIO;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> s[i][j];
        }
    }

    recur(0);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }

    cout << '\n';
    return 0;
}
