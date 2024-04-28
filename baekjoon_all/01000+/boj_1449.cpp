// Solve 2024-04-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int arr[1000];

int main() {
    FASTIO;

    int n, l;
    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    int ans = 0;
    int i = 0;

    while (i < n) {
        ans++;
        int ni = i + 1;

        while (ni < n && arr[ni] < arr[i] + l) {
            ni++;
        }

        i = ni;
    }

    cout << ans << '\n';

    return 0;
}
