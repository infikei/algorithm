// Solve 2025-05-19

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

struct Student{
    string name;
    int score;
    int risk;
    int cost;
    int janghak;

    Student(string name, int score, int risk, int cost) : name(name), score(score), risk(risk), cost(cost) {
        janghak = score * score * score / (cost * (risk + 1));
    }

    bool operator<(const Student& rhs) const {
        if (janghak != rhs.janghak) {
            return janghak > rhs.janghak;
        }
        if (cost != rhs.cost) {
            return cost < rhs.cost;
        }
        return name < rhs.name;
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<Student> students;

    for (int i = 0; i < n; i++) {
        string name;
        int score, risk, cost;
        cin >> name >> score >> risk >> cost;
        students.emplace_back(name, score, risk, cost);
    }

    sort(students.begin(), students.end());
    cout << students[1].name << '\n';
    return 0;
}
