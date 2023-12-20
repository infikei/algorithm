// Solve 2022-06-03
// Update 2023-12-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    unordered_set<int> num_set;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        num_set.insert(num);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;

        if (num_set.find(num) != num_set.end()) {
            cout << 1 << ' ';
        }
        else {
            cout << 0 << ' ';
        }
    }

    cout << '\n';

    return 0;
}
