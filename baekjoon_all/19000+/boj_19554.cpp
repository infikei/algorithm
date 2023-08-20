// Solve 2023-08-18

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    int ans = 1;

    int low = 0, high = n + 1;

    while (low + 1 < high) {
        int mid = (low + high) >> 1;
        int val;

        cout << "? " << mid << endl;
        cin >> val;

        if (val == -1) {
            low = mid;
        }
        else if (val == 1) {
            high = mid;
        }
        else {
            ans = mid;
            break;
        }
    }

    cout << "= " << ans << endl;

    return 0;
}
