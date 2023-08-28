// Solve 2022-06-07
// Update 2023-08-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int arr[5];

    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    cout << *min_element(arr, arr + 3) + *min_element(arr + 3, arr + 5) - 50 << '\n';

    return 0;
}
