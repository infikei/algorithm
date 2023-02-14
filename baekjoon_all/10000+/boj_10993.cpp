// Solve 2023-02-14

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

vector<string> make_triangle(int x) {
    vector<string> res;
    if (x == 1) {
        res = { " ", "*" };
        return res;
    }

    vector<string> res_small = make_triangle(x - 1);
    reverse(ALL(res_small));

    int row_end = (1 << x) - 1;
    res.assign(row_end + 1, "");

    int i_end = row_end * 2 - 1;
    for (int i = 1; i <= i_end; i++) {
        res[row_end] += "*";
    }

    string tmp = "";
    for (int row = row_end - 1; row >= 1; row--) {
        tmp += ' ';
        res[row] += tmp + '*';
    }

    tmp = " ";
    i_end = row_end / 2 + 1;
    for (int row = 2; row < i_end; row++) {
        res[row] += tmp + "*";
        tmp += "  ";
    }

    tmp = "";
    int k = 0;
    for (int row = i_end; row < row_end; row++) {
        res[row] += tmp + res_small[k] + tmp + tmp + "*";
        tmp += " ";
        k++;
    }

    return res;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<string> ans = make_triangle(n);
    ans.erase(ans.begin(), ans.begin() + 1);
    if (~n & 1) {
        reverse(ALL(ans));
    }
    for (auto a : ans) {
        cout << a << '\n';
    }

    return 0;
}