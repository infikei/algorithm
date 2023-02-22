// Solve 2023-02-22

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
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int sum_hakjum = 0, sum_hakjum_grade10 = 0;

    for (int i = 0; i < 20; i++) {
        string subject_name, grade_str;
        double hakjum_d;
        cin >> subject_name >> hakjum_d >> grade_str;

        if (grade_str == "P") continue;

        int hakjum = hakjum_d;
        int grade10 = 0;
        if (grade_str != "F") {
            if (grade_str[0] == 'A') {
                grade10 = 40;
            }
            else if (grade_str[0] == 'B') {
                grade10 = 30;
            }
            else if (grade_str[0] == 'C') {
                grade10 = 20;
            }
            else if (grade_str[0] == 'D') {
                grade10 = 10;
            }

            if (grade_str[1] == '+') {
                grade10 += 5;
            }
        }

        sum_hakjum += hakjum;
        sum_hakjum_grade10 += hakjum * grade10;
    }

    SETPRECISION(6);
    cout << (double)sum_hakjum_grade10 / 10 / sum_hakjum << '\n';

    return 0;
}