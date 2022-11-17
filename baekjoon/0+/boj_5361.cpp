#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

double price[5] = {350.34, 230.90, 190.55, 125.30, 180.90};

int main() {
    fastio;

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        double ans = 0;

        for (int i = 0; i < 5; i++) {
            int x;
            cin >> x;
            ans += price[i] * x;
        }

        cout << fixed;
        cout.precision(2);
        cout << '$' << ans << '\n';
    }

    return 0;
}