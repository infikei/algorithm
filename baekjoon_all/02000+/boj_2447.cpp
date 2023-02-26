// Solve 2023-02-08
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
    if (k == 3) {
        return {"   ", "***", "* *", "***"};
    }

    int k3 = k / 3;
    vector<string> small_square = make_square(k3);

    vector<string> square;
    square.push_back(small_square[0] + small_square[0] + small_square[0]);
    for (int i = 1; i <= k3; i++) {
        square.push_back(small_square[i] + small_square[i] + small_square[i]);
    }
    for (int i = 1; i <= k3; i++) {
        square.push_back(small_square[i] + small_square[0] + small_square[i]);
    }
    for (int i = 1; i <= k3; i++) {
        square.push_back(square[i]);
    }
    return square;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<string> square = make_square(n);
    for (int i = 1; i <= n; i++) {
        cout << square[i] << '\n';
    }

    return 0;
}