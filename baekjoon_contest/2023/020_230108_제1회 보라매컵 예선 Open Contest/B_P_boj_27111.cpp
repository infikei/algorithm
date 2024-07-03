// Solve 2023-01-08
// Update 2023-12-23

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

    vector<int> visited(200001, 0);
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if (visited[a] == b) cnt++;
        else visited[a] = b;
    }

    for (int i = 1; i <= 200000; i++) {
        if (visited[i] == 1) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
