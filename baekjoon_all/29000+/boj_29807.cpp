// Solve 2023-09-16
// Update 2024-07-11

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    int scores[5] = { 0 };

    for (int i = 0; i < t; i++) {
        cin >> scores[i];
    }

    int student_num = 0;

    if (scores[0] > scores[2]) {
        student_num += (scores[0] - scores[2]) * 508;
    }
    else {
        student_num += (scores[2] - scores[0]) * 108;
    }

    if (scores[1] > scores[3]) {
        student_num += (scores[1] - scores[3]) * 212;
    }
    else {
        student_num += (scores[3] - scores[1]) * 305;
    }

    student_num += scores[4] * 707;
    student_num *= 4763;

    cout << student_num << '\n';

    return 0;
}
