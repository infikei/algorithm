// Solve 2024-03-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int arr[100001];

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;

            arr[a] = b;
        }

        int desc_cnt = 1;
        int desc_val = arr[1];

        for (int a = 2; a <= n; a++) {
            if (desc_val > arr[a]) {
                desc_val = arr[a];
                desc_cnt++;
            }
        }

        cout << desc_cnt << '\n';
    }

    return 0;
}
