// Solve 2022-11-03
// Update 2023-08-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int limit, speed;
    cin >> limit >> speed;

    int diff = speed - limit;

    if (diff <= 0) {
        cout << "Congratulations, you are within the speed limit!\n";
    }
    else if (diff <= 20) {
        cout << "You are speeding and your fine is $100.\n";
    }
    else if (diff <= 30) {
        cout << "You are speeding and your fine is $270.\n";
    }
    else {
        cout << "You are speeding and your fine is $500.\n";
    }

    return 0;
}
