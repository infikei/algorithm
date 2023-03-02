// Solve 2023-03-02

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

    int n, k;
    cin >> n >> k;

    vector<vector<int> > pascal_triangle;
    pascal_triangle.assign(n, vector<int>(n, 1));
    for (int row = 2; row < n; row++) {
        for (int col = 1; col < row; col++) {
            pascal_triangle[row][col] = pascal_triangle[row - 1][col - 1] + pascal_triangle[row - 1][col];
        }
    }
    cout << pascal_triangle[n - 1][k - 1] << '\n';

    return 0;
}