// Solve 2023-08-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Student{
    string name;
    int kor, eng, mat;

    bool operator<(const Student &rhs) const {
        if (kor != rhs.kor) return kor > rhs.kor;
        if (eng != rhs.eng) return eng < rhs.eng;
        if (mat != rhs.mat) return mat > rhs.mat;
        return name < rhs.name;
    }
};

Student student[100000];

istream& operator>>(istream &is, Student &rhs) {
    return is >> rhs.name >> rhs.kor >> rhs.eng >> rhs.mat;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> student[i];
    }

    sort(student, student + n);

    for (int i = 0; i < n; i++) {
        cout << student[i].name << '\n';
    }

    return 0;
}
