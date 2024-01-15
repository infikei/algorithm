// Solve 2024-01-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        vec[i] = max(0, b - a);
    }

    sort(vec.begin(), vec.end());

    cout << vec[k - 1] << '\n';

    return 0;
}
