// Solve 2023-03-27
// Update 2023-08-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

vector<string> cantor(int k) {
    if (k == 0) return { " ", "-" };

    vector<string> prev_cantor = cantor(k - 1);
    vector<string> res;

    res.push_back(prev_cantor[0] + prev_cantor[0] + prev_cantor[0]);
    res.push_back(prev_cantor[1] + prev_cantor[0] + prev_cantor[1]);

    return res;
}

int main() {
    FASTIO;

    int n;

    while (cin >> n) {
        cout << cantor(n)[1] << '\n';
    }

    return 0;
}
