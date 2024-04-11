// Solve 2024-04-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int arr[50001];
int idx[50001];
int ans[50001];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        arr[i] = x;
        idx[x] = i;
    }

    for (int i = 1; i <= n; i++) {
        if (ans[i] > 0) continue;

        int x = arr[i];

        if (idx[x] < idx[x - 1]) {
            ans[i] = x - 1;
            ans[idx[x - 1]] = x;
        }
        else {
            ans[i] = x;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }

    cout << '\n';

    return 0;
}
