// Solve 2022-12-24
// Update 2023-11-21

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

    vector<int> route(n);
    int k = 0;

    for (int i = 0; i < n; i++) {
        int city;
        cin >> city;

        route[i] = city;
        k = max(k, city);
    }

    k++;
    vector<int> parent(k, -2);
    parent[route[0]] = -1;

    for (int i = 1; i < n; i++) {
        if (parent[route[i]] == -2) {
            parent[route[i]] = route[i - 1];
        }
    }

    cout << k << '\n';

    for (int city : parent) {
        cout << city << ' ';
    }

    cout << '\n';

    return 0;
}
