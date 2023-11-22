// Solve 2023-04-28
// Update 2023-11-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int x[4], y[4];

    for (int i = 0; i < 4; i++) {
        cin >> x[i] >> y[i];
    }

    int x_flag;

    if (x[1] < x[2] || x[3] < x[0]) {
        x_flag = 0;
    }
    else if (x[1] == x[2] || x[3] == x[0]) {
        x_flag = 1;
    }
    else {
        x_flag = 2;
    }

    int y_flag;

    if (y[1] < y[2] || y[3] < y[0]) {
        y_flag = 0;
    }
    else if (y[1] == y[2] || y[3] == y[0]) {
        y_flag = 1;
    }
    else {
        y_flag = 2;
    }

    if (x_flag == 0 || y_flag == 0) {
        cout << "NULL\n";
    }
    else if (x_flag == 1 && y_flag == 1) {
        cout << "POINT\n";
    }
    else if (x_flag == 1 || y_flag == 1) {
        cout << "LINE\n";
    }
    else {
        cout << "FACE\n";
    }

    return 0;
}
