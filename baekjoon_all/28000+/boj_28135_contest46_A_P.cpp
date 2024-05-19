// Solve 2023-05-27
// Update 2024-05-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    vector<int> v;

    for (int i = 0; i < 10000; i++) {
        v.push_back(i * 100 + 50); // ????50
        v.push_back(500000 + i); // 50????
    }

    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 10; j++) {
            v.push_back(i * 1000 + 500 + j); // ???50?
            v.push_back(j * 100000 + 50000 + i); // ?50???
        }
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            v.push_back(i * 10000 + 5000 + j); // ??50??
        }
    }

    // 정렬 후 중복 제거
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int n;
    cin >> n;

    int ans = lower_bound(v.begin(), v.end(), n) - v.begin();
    ans += n;
    cout << ans << '\n';

    return 0;
}
