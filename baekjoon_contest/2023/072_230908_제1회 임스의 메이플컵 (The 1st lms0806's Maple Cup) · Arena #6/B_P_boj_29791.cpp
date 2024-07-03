// Solve 2023-09-08
// Update 2023-12-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    int arr[1000000];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    int cnt_a = 1;
    int cur = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] >= cur + 100) {
            cnt_a++;
            cur = arr[i];
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + m);
    int cnt_b = 1;
    cur = arr[0];

    for (int i = 1; i < m; i++) {
        if (arr[i] >= cur + 360) {
            cnt_b++;
            cur = arr[i];
        }
    }

    cout << cnt_a << ' ' << cnt_b << '\n';

    return 0;
}
