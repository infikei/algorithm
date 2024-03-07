// Solve 2024-03-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int problem_count = 0;
    string s;
    getline(cin, s);

    while (true) {
        getline(cin, s);

        if (s == "문제") {
            problem_count++;
        }
        else if (s == "고무오리") {
            if (--problem_count == -1) {
                problem_count = 2;
            }
        }
        else {
            break;
        }
    }

    cout << (problem_count == 0 ? "고무오리야 사랑해\n" : "힝구\n");

    return 0;
}
