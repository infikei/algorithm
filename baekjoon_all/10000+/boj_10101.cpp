// Solve 2022-07-12
// Update 2023-03-14

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int a, b, c;
    cin >> a >> b >> c;

    if (a + b + c != 180) {
        cout << "Error\n";
    }
    else if (a == 60 && b == 60) {
        cout << "Equilateral\n";
    }
    else if (a == b || b == c || c == a) {
        cout << "Isosceles\n";
    }
    else {
        cout << "Scalene\n";
    }

    return 0;
}
