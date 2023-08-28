// Solve 2022-07-20
// Update 2023-08-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    bool students[31] = { false };

    for (int i = 0; i < 28; i++) {
        int student_id;
        cin >> student_id;

        students[student_id] = true;
    }

    for (int i = 1; i <= 30; i++) {
        if (!students[i]) {
            cout << i << '\n';
        }
    }

    return 0;
}
