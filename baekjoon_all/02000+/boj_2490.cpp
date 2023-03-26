// Solve 2022-06-14
// Update 2023-03-26

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

int main() {
    FASTIO;

    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            int x;
            cin >> x;
            sum += x;
        }

        if (sum == 0) {
            cout << "D\n";
        }
        else if (sum == 1) {
            cout << "C\n";
        }
        else if (sum == 2) {
            cout << "B\n";
        }
        else if (sum == 3) {
            cout << "A\n";
        }
        else {
            cout << "E\n";
        }
    }

    return 0;
}
