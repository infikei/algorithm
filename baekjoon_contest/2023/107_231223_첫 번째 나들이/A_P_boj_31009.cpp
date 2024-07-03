// Solve 2023-12-23

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

    vector<int> costs;
    int jinju_cost = 0;

    for (int i = 0; i < n; i++) {
        string d;
        int c;
        cin >> d >> c;

        costs.push_back(c);

        if (d == "jinju") jinju_cost = c;
    }

    sort(costs.begin(), costs.end());
    int cnt = costs.end() - upper_bound(costs.begin(), costs.end(), jinju_cost);

    cout << jinju_cost << '\n';
    cout << cnt << '\n';

    return 0;
}
