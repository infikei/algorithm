// Solve 2022-08-20
// Update 2023-12-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int arr[21];

    for (int i = 1; i <= 20; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < 10; i++) {
        int a, b;
        cin >> a >> b;

        reverse(arr + a, arr + b + 1);
    }

    for (int i = 1; i <= 20; i++) {
        cout << arr[i] << ' ';
    }

    cout << '\n';

    return 0;
}
