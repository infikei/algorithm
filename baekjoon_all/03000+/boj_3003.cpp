// Solve 2022-11-06
// Update 2023-10-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int arr[6] = { 1, 1, 2, 2, 2, 8 };

    for (int i = 0; i < 6; i++) {
        int x;
        cin >> x;

        cout << arr[i] - x << ' ';
    }

    cout << '\n';

    return 0;
}
