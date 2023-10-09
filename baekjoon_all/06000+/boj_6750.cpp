// Solve 2023-10-08

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string word;
    cin >> word;

    bool ans = true;
    char targets[7] = { 'I', 'O', 'S', 'H', 'Z', 'X', 'N' };

    for (char &ch : word) {
        bool check_in_target = false;

        for (int i = 0; i < 7; i++) {
            if (ch == targets[i]) {
                check_in_target = true;
                break;
            }
        }

        if (!check_in_target) {
            ans = false;
            break;
        }
    }

    if (ans) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
