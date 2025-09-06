// Solve 2023-08-13

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string s;
    int ans = 0;

    for (int i = 0; i < 3; i++) {
        cin >> s;

        if (s[0] < 'A') {
            ans = stoi(s) + 3 - i;
        }
    }

    if (ans % 3 == 0) {
        if (ans % 5 == 0) {
            cout << "FizzBuzz\n";
        }
        else {
            cout << "Fizz\n";
        }
    }
    else {
        if (ans % 5 == 0) {
            cout << "Buzz\n";
        }
        else {
            cout << ans << '\n';
        }
    }

    return 0;
}
