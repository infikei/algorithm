// Solve 2026-01-04

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

ll a[500001];

int main() {
    FASTIO;

    int n;
    cin >> n;
    ll s = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }

    sort(a, a + n);

    ll cnt = 0;

    // Case 1 : 다른 모든 원소의 합으로 가장 큰 수를 고르는 경우

    ll k = s - a[n - 1] * 2; // 제거해야 하는 두 수의 합
    int i = 0;
    int j = n - 2;

    while (i < j) {
        if (a[i] + a[j] < k) {
            i++;
        }
        else if (a[i] + a[j] > k) {
            j--;
        }
        else {
            cnt += upper_bound(a + (i + 1), a + (j + 1), k - a[i]) - lower_bound(a + (i + 1), a + (j + 1), k - a[i]);
            i++;
        }
    }

    // Case 2 : 다른 모든 원소의 합으로 두 번째로 큰 수를 고르는 경우
    // => 가장 큰 수를 제거하고, 다른 하나의 수를 추가로 제거해야 함

    k = s - a[n - 2] * 2 - a[n - 1]; // 제거해야 하는 수
    cnt += upper_bound(a, a + (n - 2), k) - lower_bound(a, a + (n - 2), k);

    // Case 3 : 다른 모든 원소의 합으로 세 번째로 큰 수를 고르는 경우
    // => 가장 큰 2개의 수를 모두 제거해야 함

    k = s - a[n - 3] * 2;

    if (a[n - 2] + a[n - 1] == k) {
        cnt++;
    }

    cout << cnt << '\n';
    return 0;
}
