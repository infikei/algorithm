// Solve 2022-07-31
// Update 2024-03-17

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string grade;
    cin >> grade;

    double score;

    if (grade == "F") {
        score = 0;
    }
    else {
        score = 4 - (grade[0] - 'A');

        if (grade[1] == '+') {
            score += 0.3;
        }
        else if (grade[1] == '-') {
            score -= 0.3;
        }
    }

    SETPRECISION(1);

    cout << score << '\n';

    return 0;
}
