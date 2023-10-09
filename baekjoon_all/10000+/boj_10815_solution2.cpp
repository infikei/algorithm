// Solve 2022-06-03
// Update 2023-10-09

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int num_list[500000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num_list[i];
    }

    sort(num_list, num_list + n);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;

        if (binary_search(num_list, num_list + n, num)) {
            cout << 1 << ' ';
        }
        else {
            cout << 0 << ' ';
        }
    }

    cout << '\n';

    return 0;
}
