#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    cout << "n e\n";
    cout << "- -----------\n";

    double e = 0;
    int fac = 1;
    for (int i = 0; i < 10; i++) {
        if (i > 0) fac *= i;
        e += 1 / (double)fac;

        cout << i << ' ';
        if (i > 2) {
            cout << fixed;
            cout.precision(9);
        }
        cout << e << '\n';
    }

    return 0;
}