// Solve 2023-12-21

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

    for (int ni = 0; ni < n; ni++) {
        string name;
        int grade;
        cin >> name >> grade;

        cout << name << ' ';

        if (grade >= 97) cout << "A+\n";
        else if (grade >= 90) cout << "A\n";
        else if (grade >= 87) cout << "B+\n";
        else if (grade >= 80) cout << "B\n";
        else if (grade >= 77) cout << "C+\n";
        else if (grade >= 70) cout << "C\n";
        else if (grade >= 67) cout << "D+\n";
        else if (grade >= 60) cout << "D\n";
        else cout << "F\n";
    }

    return 0;
}
