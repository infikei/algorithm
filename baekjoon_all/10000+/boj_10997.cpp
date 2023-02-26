// Solve 2023-02-15
// Update 2023-02-26

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

vector<string> make_square(int k) {
    if (k == 1) {
        return { "*" };
    }
    if (k == 2) {
        return { "*****", "*    ", "* ***", "* * *", "* * *", "*   *", "*****" };
    }

    vector<string> res;
    vector<string> small_square = make_square(k - 1);

    string tmp1, tmp2;
    tmp1.assign(k * 4 - 3, '*');
    tmp2.assign(k * 4 - 5, ' ');

    res.push_back(tmp1);
    res.push_back("*" + tmp2 + " ");
    res.push_back("* " + small_square[0] + "**");
    int i_end = SIZE(small_square);
    for (int i = 1; i < i_end; i++) {
        res.push_back("* " + small_square[i] + " *");
    }
    res.push_back("*" + tmp2 + "*");
    res.push_back(tmp1);

    return res;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<string> square = make_square(n);
    if (n > 1) {
        square[1] = "*";
    }
    for (auto line : square) {
        cout << line << '\n';
    }

    return 0;
}