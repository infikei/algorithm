// Solve 2023-02-14
// Update 2023-08-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

vector<string> make_triangle(int k) {
    if (k == 1) return { "*" };

    vector<string> small_triangle = make_triangle(k - 1);
    reverse(small_triangle.begin(), small_triangle.end());

    vector<string> triangle;
    triangle.assign((1 << k) - 1, "");

    triangle[0].assign(SIZE(small_triangle.back()) + (1 << k), '*');

    int row = 1, row_end = (1 << (k - 1)) - 1;
    string space, space2(row_end, ' ');

    while (row <= row_end) {
        space += " ";
        space2.pop_back();

        triangle[row] = space + "*" + space2 + small_triangle[row - 1] + space2 + space2 + "*";

        row++;
    }

    row_end <<= 1;
    space2.assign((1 << (k - 1)) - 2, ' ');

    while (row < row_end) {
        space += " ";
        space2.pop_back();

        triangle[row] = space + "*" + space2 + space2 + " *";

        row++;
    }

    triangle[row] = space + " *";

    return triangle;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<string> triangle = make_triangle(n);
    if (n & 1) reverse(triangle.begin(), triangle.end());

    for (const string &line : triangle) {
        cout << line << '\n';
    }

    return 0;
}
