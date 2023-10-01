// Solve 2023-09-30

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, d;
    cin >> n >> d;

    vector<int> vec(n);
    int vec_sum = 0;

    for (int &x : vec) {
        cin >> x;

        vec_sum += x;
    }

    int reward_per_problem = d / vec_sum;

    for (int &x : vec) {
        cout << reward_per_problem * x << '\n';
    }

    return 0;
}
