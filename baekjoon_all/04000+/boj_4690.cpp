// Solve 2023-02-25
// Update 2023-08-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    for (int a = 2; a <= 100; a++) {
        int a3 = a * a * a;

        for (int b = 2; b < a; b++) {
            int b3 = b * b * b;

            for (int c = b; c < a; c++) {
                int c3 = c * c * c;

                for (int d = c; d < a; d++) {
                    int d3 = d * d * d;

                    if (a3 == b3 + c3 + d3) {
                        cout << "Cube = " << a << ", Triple = (" << b << ',' << c << ',' << d << ")\n";
                    }
                }
            }
        }
    }

    return 0;
}
