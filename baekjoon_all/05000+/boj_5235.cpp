// Solve 2023-10-05

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

        int even_sum = 0, odd_sum = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (x % 2 == 0) even_sum += x;
            else odd_sum += x;
        }

        if (even_sum > odd_sum) cout << "EVEN\n";
        else if (even_sum < odd_sum) cout << "ODD\n";
        else cout << "TIE\n";
    }

    return 0;
}
