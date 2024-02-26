// Solve 2024-02-25

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

    int numbers[100000];

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    sort(numbers, numbers + n);
    int min_diff = 2'000'000'000;
    int begin_idx = 0;
    int end_idx = 0;

    while (end_idx < n) {
        int cur_diff = numbers[end_idx] - numbers[begin_idx];

        if (cur_diff < m) {
            end_idx++;
        }
        else if (cur_diff > m) {
            min_diff = min(min_diff, cur_diff);
            begin_idx++;
        }
        else {
            min_diff = cur_diff;
            break;
        }
    }

    cout << min_diff << '\n';

    return 0;
}
