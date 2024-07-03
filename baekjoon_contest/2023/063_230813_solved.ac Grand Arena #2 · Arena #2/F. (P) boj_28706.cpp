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

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;

        vector<vector<int> > vec(2, vector<int>(7));
        vec[0][1] = 1;

        for (int ni = 0; ni < n; ni++) {
            char op, op2;
            int x, x2;
            cin >> op >> x >> op2 >> x2;

            for (int i = 0; i < 7; i++) {
                if (vec[0][i] == 0) continue;

                if (op == '+') {
                    vec[1][(i + x) % 7] = 1;
                }
                else {
                    vec[1][(i * x) % 7] = 1;
                }

                if (op2 == '+') {
                    vec[1][(i + x2) % 7] = 1;
                }
                else {
                    vec[1][(i * x2) % 7] = 1;
                }
            }

            for (int i = 0; i < 7; i++) {
                vec[0][i] = vec[1][i];
                vec[1][i] = 0;
            }
        }

        if (vec[0][0] != 0) {
            cout << "LUCKY\n";
        }
        else {
            cout << "UNLUCKY\n";
        }
    }

    return 0;
}
