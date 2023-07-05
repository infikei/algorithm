// Solve 2023-07-04

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    int sum_cnt = 0;
    double sum_prod = 0.0;

    for (int i = 0; i < n; i++) {
        string grade_str;
        int cnt;
        cin >> grade_str >> cnt >> grade_str;

        double grade = 0.0;
        if (grade_str == "A+") grade = 4.3;
        else if (grade_str == "A0") grade = 4.0;
        else if (grade_str == "A-") grade = 3.7;
        else if (grade_str == "B+") grade = 3.3;
        else if (grade_str == "B0") grade = 3.0;
        else if (grade_str == "B-") grade = 2.7;
        else if (grade_str == "C+") grade = 2.3;
        else if (grade_str == "C0") grade = 2.0;
        else if (grade_str == "C-") grade = 1.7;
        else if (grade_str == "D+") grade = 1.3;
        else if (grade_str == "D0") grade = 1.0;
        else if (grade_str == "D-") grade = 0.7;

        sum_cnt += cnt;
        sum_prod += cnt * grade;
    }

    double ans = sum_prod / sum_cnt;
    ans = round(ans * 100) / 100;
    SETPRECISION(2);
    cout << ans << '\n';

    return 0;
}
