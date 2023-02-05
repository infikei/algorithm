#include <iostream>
#include <cmath>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using ull = unsigned long long;

int N, K, R, Q;
int typhoon[200001][3];

void input() {
    cin >> N >> K >> R >> Q;
    int prev_day;
    cin >> prev_day;
    cin >> typhoon[prev_day][0] >> typhoon[prev_day][1];

    for (int k = 1; k < K; k++) {
        int day;
        cin >> day;
        cin >> typhoon[day][0] >> typhoon[day][1];

        int dx = 0, dy = 0;
        if (typhoon[prev_day][0] == typhoon[day][0]) {
            dy = 1;
            if (typhoon[prev_day][1] > typhoon[day][1]) {
                dy = -1;
            }
        }
        else {
            dx = 1;
            if (typhoon[prev_day][0] > typhoon[day][0]) {
                dx = -1;
            }
        }

        typhoon[prev_day][2] = dx + 2 * dy;
        int i = prev_day + 1;
        while (i < day) {
            typhoon[i][0] = typhoon[i - 1][0] + dx;
            typhoon[i][1] = typhoon[i - 1][1] + dy;
            typhoon[i][2] = typhoon[i - 1][2];
            i++;
        }
        prev_day = day;
    }
    typhoon[N][2] = typhoon[N - 1][2];
}

void solve() {
    ull R2 = pow(R, 2);
    for (int q = 0; q < Q; q++) {
        int j, x, y;
        cin >> j >> x >> y;

        ull far2 = pow(x - typhoon[j][0], 2) + pow(y - typhoon[j][1], 2);
        if (far2 > R2) {
            cout << "gori\n";
            continue;
        }

        if (typhoon[j][2] == 1) {
            if (y > typhoon[j][1]) {
                cout << "safe\n";
            }
            else if (y < typhoon[j][1]) {
                cout << "unsafe\n";
            }
            else {
                cout << "gori\n";
            }
        }
        else if (typhoon[j][2] == -1) {
            if (y < typhoon[j][1]) {
                cout << "safe\n";
            }
            else if (y > typhoon[j][1]) {
                cout << "unsafe\n";
            }
            else {
                cout << "gori\n";
            }
        }
        else if (typhoon[j][2] == 2) {
            if (x < typhoon[j][0]) {
                cout << "safe\n";
            }
            else if (x > typhoon[j][0]) {
                cout << "unsafe\n";
            }
            else {
                cout << "gori\n";
            }
        }
        else {
            if (x > typhoon[j][0]) {
                cout << "safe\n";
            }
            else if (x < typhoon[j][0]) {
                cout << "unsafe\n";
            }
            else {
                cout << "gori\n";
            }
        }
    }
}

int main() {
    fastio;

    input();

    solve();

    return 0;
}