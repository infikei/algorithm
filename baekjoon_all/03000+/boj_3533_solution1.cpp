// Solve 2023-10-03

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int arr[10];

    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    int ans = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            ans ^= (arr[i] | arr[j]);
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            for (int k = j + 1; k < 10; k++) {
                ans ^= (arr[i] | arr[j] | arr[k]);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
