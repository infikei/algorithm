// Solve 2023-06-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

ll a[1000002];

int main() {
    FASTIO;

    int n;
    ll b, c;
    cin >> n >> b >> c;
    ll bc = b + c, bcc = bc + c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    if (b > c) {
        // b가 c보다 큰 경우, 18185번와 같은 풀이로 해결할 수 있다.
        for (int i = 0; i < n; i++) {
            if (a[i + 1] > a[i + 2]) {
                ll x5 = min(a[i], a[i + 1] - a[i + 2]);
                a[i] -= x5;
                a[i + 1] -= x5;
                ans += x5 * bc;
            }

            ll x7 = min(a[i], min(a[i + 1], a[i + 2]));
            a[i] -= x7;
            a[i + 1] -= x7;
            a[i + 2] -= x7;
            ans += x7 * bcc;

            ans += a[i] * b;
        }
    }
    else {
        // c가 b보다 크거나 같은 경우, b의 가격으로만 사는 것이 무조건 이득이다.
        for (int i = 0; i < n; i++) {
            ans += a[i];
        }
        ans *= b;
    }

    cout << ans << '\n';

    return 0;
}
