// Solve 2024-03-07
// Update 2025-03-02

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    FASTIO;

    string s;
    getline(cin, s);

    int problem_cnt = 0;

    while (true) {
        getline(cin, s);

        if (s == "문제") {
            problem_cnt++;
        }
        else if (s == "고무오리") {
            if (--problem_cnt == -1) {
                problem_cnt = 2;
            }
        }
        else {
            break;
        }
    }

    cout << (problem_cnt == 0 ? "고무오리야 사랑해" : "힝구") << '\n';

    return 0;
}
