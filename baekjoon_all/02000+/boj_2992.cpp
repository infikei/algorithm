// Solve 2023-08-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

string x, x_sort;
bool check[6];

string dfs(int depth = 0, string now = "") {
    if (depth == SIZE(x)) {
        if (now != x) return now;
        return "0";
    }

    string res = "0";

    for (int i = 0; i < SIZE(x); i++) {
        if (check[i]) continue;

        string next = now + x_sort[i];
        if (next < x.substr(0, depth + 1)) continue;

        check[i] = true;
        res = dfs(depth + 1, next);
        check[i] = false;

        if (res != "0") break;
    }

    return res;
}

int main() {
    FASTIO;

    cin >> x;

    x_sort = x;
    sort(x_sort.begin(), x_sort.end());

    cout << dfs() << '\n';

    return 0;
}
