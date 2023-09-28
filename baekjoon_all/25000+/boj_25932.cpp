// Solve 2023-09-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        if (ti >= 1) cout << '\n';

        bool zack = false, mack = false;

        int arr[10];

        for (int i = 0; i < 10; i++) {
            int x;
            cin >> x;

            arr[i] = x;

            if (x == 17) zack = true;
            else if (x == 18) mack = true;
        }

        for (int i = 0; i < 10; i++) {
            cout << arr[i] << ' ';
        }

        cout << '\n';

        if (zack) {
            if (mack) cout << "both\n";
            else cout << "zack\n";
        }
        else {
            if (mack) cout << "mack\n";
            else cout << "none\n";
        }
    }

    return 0;
}
