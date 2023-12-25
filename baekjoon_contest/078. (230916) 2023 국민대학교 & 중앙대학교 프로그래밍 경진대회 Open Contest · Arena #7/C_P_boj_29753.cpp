// Solve 2023-09-16

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    unordered_map<string, int> grade_str_to_num = {
        { "A+", 450 },
        { "A0", 400 },
        { "B+", 350 },
        { "B0", 300 },
        { "C+", 250 },
        { "C0", 200 },
        { "D+", 150 },
        { "D0", 100 },
        { "F", 0 }
    };

    string grade_str[9] = { "F", "D0", "D+", "C0", "C+", "B0", "B+", "A0", "A+" };
    int grade_num[9] = { 0, 100, 150, 200, 250, 300, 350, 400, 450 };
    int expected_grade_avr[9];

    int n;
    double x;
    cin >> n >> x;

    int min_grade_avr = round(x * 100);

    int hak_sum = 0, grade_sum = 0;

    for (int i = 1; i < n; i++) {
        int hak;
        string grade;
        cin >> hak >> grade;

        hak_sum += hak;
        grade_sum += hak * grade_str_to_num[grade];
    }

    int hak;
    cin >> hak;

    hak_sum += hak;

    for (int i = 0; i < 9; i++) {
        int expected_grade_sum = grade_sum + hak * grade_num[i];
        expected_grade_avr[i] = expected_grade_sum / hak_sum;
    }

    int pos = upper_bound(expected_grade_avr, expected_grade_avr + 9, min_grade_avr) - expected_grade_avr;

    if (pos == 9) cout << "impossible\n";
    else cout << grade_str[pos] << '\n';

    return 0;
}
