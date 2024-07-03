// Solve 2023-11-18

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

vector<string> create_star(int depth) {
    if (depth == 0) {
        return { " ", "*" };
    }

    vector<string> prev = create_star(depth - 1);
    vector<string> result;

    result.push_back(prev[0] + prev[0] + prev[0] + prev[0] + prev[0]);

    for (int i = 1; i < SIZE(prev); i++) {
        result.push_back(prev[0] + prev[0] + prev[i] + prev[0] + prev[0]);
    }
    for (int i = 1; i < SIZE(prev); i++) {
        result.push_back(prev[0] + prev[0] + prev[i] + prev[0] + prev[0]);
    }
    for (int i = 1; i < SIZE(prev); i++) {
        result.push_back(prev[i] + prev[i] + prev[i] + prev[i] + prev[i]);
    }
    for (int i = 1; i < SIZE(prev); i++) {
        result.push_back(prev[0] + prev[i] + prev[i] + prev[i] + prev[0]);
    }
    for (int i = 1; i < SIZE(prev); i++) {
        result.push_back(prev[0] + prev[i] + prev[0] + prev[i] + prev[0]);
    }

    return result;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<string> star = create_star(n);

    for (int i = 1; i < SIZE(star); i++) {
        cout << star[i] << '\n';
        // cout << '[' << star[i] << ']' << '\n';
    }

    return 0;
}
