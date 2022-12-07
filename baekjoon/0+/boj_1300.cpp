#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;

ll less_than_or_equal_to_mid(ll mid, ll n) {
    ll cnt = 0;

    for (ll i = 1; i <= n; i++) {
        cnt += min(mid / i, n);
    }

    return cnt;
}

int main() {
    fastio;

    ll N, K;
    cin >> N >> K;

    ll low = 1, high = N * N, mid;

    while (low <= high) {
        mid = (low + high) / 2;
        ll cnt = less_than_or_equal_to_mid(mid, N);

        if (cnt < K) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << low << '\n';

    return 0;
}