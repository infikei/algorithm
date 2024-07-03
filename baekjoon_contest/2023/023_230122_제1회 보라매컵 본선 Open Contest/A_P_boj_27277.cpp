// Solve 2023-01-22
// Update 2023-12-25

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

    vector<int> vec(n);

    for (int &x : vec) {
        cin >> x;
    }

    sort(vec.begin(), vec.end());

    int ans = vec[n - 1];
    int i = 0;
    int j = n - 2;

    while (i < j) {
        ans += vec[j] - vec[i];
        i++; j--;
    }

    cout << ans << '\n';

    return 0;
}
