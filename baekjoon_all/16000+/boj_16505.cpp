// Solve 2023-06-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

vector<string> make_stars(int k) {
    if (k == 0) return { "*" };

    vector<string> prev_stars = make_stars(k - 1);
    vector<string> res = prev_stars;
    for (int i = 0; i < SIZE(prev_stars); i++) {
        for (int j = 0; j < i; j++) {
            res[i] += ' ';
        }
        res[i] += prev_stars[i];
        res.push_back(prev_stars[i]);
    }
    return res;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<string> ans = make_stars(n);

    for (auto &s : ans) {
        cout << s << '\n';
    }

    return 0;
}
