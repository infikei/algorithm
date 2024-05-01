// Solve 2024-04-30

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int arr[50];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cnt = 0;
    int cur = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > cur) {
            cur = arr[i];
            cnt++;
        }
    }

    cout << cnt << '\n';

    cnt = 0;
    cur = -1;

    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > cur) {
            cur = arr[i];
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
