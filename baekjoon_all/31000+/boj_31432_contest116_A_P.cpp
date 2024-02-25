// Solve 2024-02-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<int> digits(n);

    for (int &d : digits) {
        cin >> d;
    }

    cout << "YES\n";

    if (digits[0] <= 1) {
        cout << digits[0] << '\n';
    }
    else {
        cout << digits[0] << digits[0] << '\n';
    }

    return 0;
}
