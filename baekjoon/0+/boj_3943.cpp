#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;

        int ans = n;
        while (n > 1) {
            if (n % 2 == 0) n /= 2;
            else n = n * 3 + 1;
            ans = max(ans, n);
        }

        cout << ans << '\n';
    }

    return 0;
}