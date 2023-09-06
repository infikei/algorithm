// Solve 2022-11-26
// Update 2023-09-06

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

        string max_school_name;
        int max_school_val = -1;

        for (int i = 0; i < n; i++) {
            string school_name;
            int school_val;
            cin >> school_name >> school_val;

            if (school_val > max_school_val) {
                max_school_val = school_val;
                max_school_name = school_name;
            }
        }

        cout << max_school_name << '\n';
    }

    return 0;
}
