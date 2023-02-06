#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti++) {
        double d, f, p;
        cin >> d >> f >> p;

        cout << fixed;
        cout.precision(2);
        cout << '$' << d * f * p << '\n';
    }

    return 0;
}