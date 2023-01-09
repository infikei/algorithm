#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int tc;
    cin >> tc;

    for (int tci = 0; tci < tc; tci++) {
        int n;
        cin >> n;

        int store_min, store_max;
        cin >> store_min;
        store_max = store_min;

        for (int i = 1; i < n; i++) {
            int x;
            cin >> x;
            store_min = min(store_min, x);
            store_max = max(store_max, x);
        }

        int ans = 2 * (store_max - store_min);
        cout << ans << '\n';
    }

    return 0;
}