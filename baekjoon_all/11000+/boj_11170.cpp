#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int count_zero(int k) {
    int res = 0;
    res += k / 10 + 1;
    res += max(0, (k / 100 - 1) * 10 + min(10, k % 100 + 1));
    res += max(0, (k / 1000 - 1) * 100 + min(100, k % 1000 + 1));
    res += max(0, (k / 10000 - 1) * 1000 + min(1000, k % 10000 + 1));
    res += max(0, (k / 100000 - 1) * 10000 + min(10000, k % 100000 + 1));
    res += max(0, (k / 1000000 - 1) * 100000 + min(100000, k % 1000000 + 1));
    return res;
}

int main() {
    fastio;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n, m;
        cin >> n >> m;
        int ans = count_zero(m);
        if (n > 0) ans -= count_zero(n - 1);
        cout << ans << '\n';
    }

    return 0;
}