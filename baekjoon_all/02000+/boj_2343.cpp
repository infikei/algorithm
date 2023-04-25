// Solve 2023-04-24

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] += v[i - 1];
    }

    int left = 0;
    int right = 1e9;
    while (left + 1 < right) {
        int mid = (left + right) >> 1;
        auto k = v.begin();
        for (int i = 0; i < m; i++) {
            k = upper_bound(k, v.end(), *k + mid) - 1;
        }

        if (*k == v.back()) {
            right = mid;
        }
        else {
            left = mid;
        }
    }

    cout << right << '\n';

    return 0;
}
