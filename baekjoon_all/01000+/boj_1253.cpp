// Solve 2025-11-25

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
int arr[2000];

bool is_good(int k) {
    int val = arr[k];
    int i = 0;
    int j = n - 1;

    while (i < j) {
        if (i == k) {
            i++;
            continue;
        }

        if (j == k) {
            j--;
            continue;
        }

        int cur = arr[i] + arr[j];

        if (cur < val) {
            i++;
        }
        else if (cur > val) {
            j--;
        }
        else return true;
    }

    return false;
}

int main() {
    FASTIO;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (is_good(i)) {
            cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}
