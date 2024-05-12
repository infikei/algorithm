// Solve 2024-05-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int arr[250001];

int main() {
    FASTIO;

    int n, x;
    cin >> n >> x;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int max_sum = 0;
    int max_cnt = 0;
    int cur_sum = 0;

    for (int i = 0; i < x; i++) {
        cur_sum += arr[i];
    }

    for (int i = x; i <= n; i++) {
        cur_sum -= arr[i - x];
        cur_sum += arr[i];

        if (cur_sum > max_sum) {
            max_sum = cur_sum;
            max_cnt = 1;
        }
        else if (cur_sum == max_sum) {
            max_cnt++;
        }
    }

    if (max_sum == 0) {
        cout << "SAD\n";
    }
    else {
        cout << max_sum << '\n';
        cout << max_cnt << '\n';
    }

    return 0;
}
