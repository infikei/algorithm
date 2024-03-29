// Solve 2023-02-08
// Update 2023-08-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

vector<string> make_triangle(int k) {
    if (k == 3) return {"   ", "  *  ", " * * ", "*****"};

    int k2 = k / 2;
    vector<string> small_triangle = make_triangle(k2);

    vector<string> triangle;
    triangle.push_back(small_triangle[0] + small_triangle[0]);

    for (int i = 1; i <= k2; i++) {
        triangle.push_back(small_triangle[0] + small_triangle[i] + small_triangle[0]);
    }
    for (int i = 1; i <= k2; i++) {
        triangle.push_back(small_triangle[i] + " " + small_triangle[i]);
    }

    return triangle;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<string> triangle = make_triangle(n);

    for (int i = 1; i <= n; i++) {
        cout << triangle[i] << '\n';
    }

    return 0;
}
