#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        double d;
        cin >> d;

        d *= 0.8;

        cout << fixed;
        cout.precision(2);
        cout << '$' << d << '\n';
    }

    return 0;
}