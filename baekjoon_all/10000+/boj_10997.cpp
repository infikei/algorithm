// Solve 2023-02-15
// Update 2023-12-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

vector<string> make_square(int k) {
    if (k == 1) return { "*" };
    if (k == 2) return { "*****", "*    ", "* ***", "* * *", "* * *", "*   *", "*****" };

    vector<string> small_square = make_square(k - 1);
    vector<string> square;
    string star(k * 4 - 3, '*');
    string space(k * 4 - 5, ' ');

    square.push_back(star);
    square.push_back("*" + space + " ");
    square.push_back("* " + small_square[0] + "**");

    for (int i = 1, i_end = SIZE(small_square); i < i_end; i++) {
        square.push_back("* " + small_square[i] + " *");
    }

    square.push_back("*" + space + "*");
    square.push_back(star);

    return square;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<string> square = make_square(n);

    if (n > 1) {
        square[1] = "*";
    }

    for (string &line : square) {
        cout << line << '\n';
    }

    return 0;
}
