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

    vector<string> square = make_square(k - 1);

    for (string &line : square) {
        line = "* " + line + " *";
    }

    square.push_back("*" + string(k * 4 - 5, ' ') + "*");
    square.push_back(string(k * 4 - 3, '*'));

    return square;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<string> square = make_square(n);

    for (int i = SIZE(square) - 1; i > 0; i--) {
        cout << square[i] << '\n';
    }

    for (string &line : square) {
        cout << line << '\n';
    }

    return 0;
}
