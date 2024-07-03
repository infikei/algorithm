// Solve 2022-10-30
// Update 2023-08-18

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

    int low = 1, high = n;

    while (low + 1 < high) {
        int mid = (low + high) / 2;
        int sheep;

        cout << "? " << mid << endl;
        cin >> sheep;

        int wolf = mid - sheep;

        if (sheep < wolf) {
            high = mid;
        }
        else if (sheep > wolf) {
            low = mid;
        }
        else {
            high = mid;
            break;
        }
    }

    cout << "! " << high << endl;

    return 0;
}
