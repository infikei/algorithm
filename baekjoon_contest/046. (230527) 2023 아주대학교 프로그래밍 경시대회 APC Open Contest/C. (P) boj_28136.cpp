// Solve 2023-05-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int n, k, arr[1000000], ans;

int main() {
    FASTIO;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 1) k = i;
    }

    int j = k;
    for (int i = 0; i < n; i++) {
        int nj = j + 1;
        if (nj == n) nj = 0;

        if (arr[j] >= arr[nj]) {
            ans++;
        }

        j = nj;
    }

    cout << ans << '\n';

    return 0;
}
