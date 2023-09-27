// Solve 2023-09-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    double weight, height;
    cin >> weight >> height;

    double bmi = weight / (height * height);

    if (bmi > 25.0) {
        cout << "Overweight\n";
    }
    else if (bmi >= 18.5) {
        cout << "Normal weight\n";
    }
    else {
        cout << "Underweight\n";
    }

    return 0;
}
