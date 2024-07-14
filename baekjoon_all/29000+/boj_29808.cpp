// Solve 2023-09-20
// Update 2024-07-12

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

struct Pair{
    int a = 0;
    int b = 0;

    Pair(int a = 0, int b = 0) : a(a), b(b) {}

    bool operator<(const Pair &rhs) const {
        if (a != rhs.a) return a < rhs.a;
        return b < rhs.b;
    }

    bool operator==(const Pair &rhs) const {
        return a == rhs.a && b == rhs.b;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int student_num;
    cin >> student_num;

    vector<Pair> answers;

    if (student_num % 4763 == 0) {
        student_num /= 4763;

        int a = 0, bb = student_num;

        while (a <= 200 && bb >= 0) {
            if (bb % 212 == 0) {
                int b = bb / 212;

                if (b >= 0 && b <= 200) {
                    answers.emplace_back(a, b);
                }
            }

            if (bb % 305 == 0) {
                int b = bb / 305;

                if (b >= 0 && b <= 200) {
                    answers.emplace_back(a, b);
                }
            }

            a++;
            bb -= 508;
        }

        a = 0, bb = student_num;

        while (a <= 200 && bb >= 0) {
            if (bb % 212 == 0) {
                int b = bb / 212;

                if (b >= 0 && b <= 200) {
                    answers.emplace_back(a, b);
                }
            }

            if (bb % 305 == 0) {
                int b = bb / 305;

                if (b >= 0 && b <= 200) {
                    answers.emplace_back(a, b);
                }
            }

            a++;
            bb -= 108;
        }

        sort(answers.begin(), answers.end());

        answers.erase(unique(answers.begin(), answers.end()), answers.end());
    }

    cout << answers.size() << '\n';

    for (Pair &ans : answers) {
        cout << ans.a << ' ' << ans.b << '\n';
    }

    return 0;
}
