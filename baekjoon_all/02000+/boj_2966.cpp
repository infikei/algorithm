// Solve 2022-12-27
// Update 2023-08-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Student{
    int score;
    string name;

    Student(int score = 0, string name = "") : score(score), name(name) {}

    bool operator<(const Student &rhs) const {
        if (score != rhs.score) return score > rhs.score;
        return name < rhs.name;
    }
};

int main() {
    FASTIO;

    int n;
    string answers;
    cin >> n >> answers;

    int cnt[3] = { 0 };
    string choose[3] = { "ABC", "BABC", "CCAABB" };
    string name[3] = { "Adrian", "Bruno", "Goran" };

    for (int i = 0; i < n; i++) {
        char c = answers[i];

        if (c == choose[0][i % 3]) cnt[0]++;
        if (c == choose[1][i % 4]) cnt[1]++;
        if (c == choose[2][i % 6]) cnt[2]++;
    }

    Student students[3];

    for (int i = 0; i < 3; i++) {
        students[i] = { cnt[i], name[i] };
    }

    sort(students, students + 3);

    cout << students[0].score << '\n';

    for (int i = 0; i < 3; i++) {
        if (students[i].score != students[0].score) break;

        cout << students[i].name << '\n';
    }

    return 0;
}
