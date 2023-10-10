// Solve 2023-02-22
// Update 2023-10-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int sum_of_hakjum = 0, sum_of_hakjum_grade = 0;

    for (int i = 0; i < 20; i++) {
        string subject_name, grade_str;
        double hakjum_d;
        cin >> subject_name >> hakjum_d >> grade_str;

        if (grade_str == "P") continue;

        int hakjum = hakjum_d;
        int grade = 0;

        if (grade_str != "F") {
            if (grade_str[0] == 'A') grade = 40;
            else if (grade_str[0] == 'B') grade = 30;
            else if (grade_str[0] == 'C') grade = 20;
            else if (grade_str[0] == 'D') grade = 10;

            if (grade_str[1] == '+') grade += 5;
        }

        sum_of_hakjum += hakjum;
        sum_of_hakjum_grade += hakjum * grade;
    }

    SETPRECISION(6);

    cout << sum_of_hakjum_grade * 0.1 / sum_of_hakjum << '\n';

    return 0;
}
