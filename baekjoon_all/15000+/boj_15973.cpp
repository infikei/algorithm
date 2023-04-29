// Solve 2023-04-28

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

    int x[4], y[4];
    for (int i = 0; i < 4; i++) {
        cin >> x[i] >> y[i];
    }

    int x_check = 0;
    if (x[1] < x[2] || x[3] < x[0]) {
        x_check = 0;
    }
    else if (x[1] == x[2] || x[3] == x[0]) {
        x_check = 1;
    }
    else {
        x_check = 2;
    }

    int y_check = 0;
    if (y[1] < y[2] || y[3] < y[0]) {
        y_check = 0;
    }
    else if (y[1] == y[2] || y[3] == y[0]) {
        y_check = 1;
    }
    else {
        y_check = 2;
    }

    if (x_check == 0 || y_check == 0) {
        cout << "NULL\n";
    }
    else if (x_check == 1 && y_check == 1) {
        cout << "POINT\n";
    }
    else if (x_check == 1 || y_check == 1) {
        cout << "LINE\n";
    }
    else {
        cout << "FACE\n";
    }

    return 0;
}
