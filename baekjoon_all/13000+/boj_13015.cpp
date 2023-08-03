// Solve 2023-02-15
// Update 2023-08-02

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

    string bar(n, '*'), middle(n * 2 - 3, ' '), blank(n - 2, ' '), left = " ";

    cout << bar << middle << bar << '\n';

    for (int iter = n - 2; iter > 0; iter--) {
        middle.pop_back();
        middle.pop_back();

        cout << left << "*" << blank << "*" << middle << "*" << blank << "*" << '\n';

        left.push_back(' ');
    }

    cout << left << "*" << blank << "*" << blank << "*" << '\n';

    for (int iter = n - 2; iter > 0; iter--) {
        left.pop_back();

        cout << left << "*" << blank << "*" << middle << "*" << blank << "*" << '\n';

        middle.push_back(' ');
        middle.push_back(' ');
    }

    cout << bar << middle << bar << '\n';

    return 0;
}
