// Solve 2023-08-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    // 1. 입력받기

    char direction;
    cin >> direction;

    vector<string> trace(2);

    for (string &s : trace) {
        cin >> s;
    }

    // 2. 회전시키기

    if (direction == 'N') {
        vector<string> new_trace(2, "**");

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                new_trace[i][j] = trace[1 - i][1 - j];
            }
        }

        swap(trace, new_trace);
    }
    else if (direction == 'E') {
        vector<string> new_trace(2, "**");

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                new_trace[i][j] = trace[1 - j][i];
            }
        }

        swap(trace, new_trace);
    }
    else if (direction == 'W') {
        vector<string> new_trace(2, "**");

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                new_trace[i][j] = trace[j][1 - i];
            }
        }

        swap(trace, new_trace);
    }

    // 3. 답 구하기

    string w = trace[0] + trace[1];

    if (w == ".OP.") cout << "T\n";
    else if (w == "I..P") cout << "F\n";
    else if (w == "O..P") cout << "Lz\n";
    else cout << "?\n";

    return 0;
}
