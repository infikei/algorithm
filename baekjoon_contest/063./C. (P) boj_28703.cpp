// Solve 2023-08-13

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
    int vec_max = 0;

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        vec_max = max(vec_max, vec[i]);
    }

    for (int i = 0; i < n; i++) {
        while (vec[i] * 2 <= vec_max) {
            vec[i] *= 2;
        }
    }

    sort(vec.begin(), vec.end());

    int ans = vec.back() - vec[0];

    for (int i = 1; i < n; i++) {
        ans = min(ans, vec[i - 1] * 2 - vec[i]);
    }

    cout << ans << '\n';

    return 0;
}
