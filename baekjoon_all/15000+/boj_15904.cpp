// Solve 2022-11-08
// Update 2023-11-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string ucpc = "UCPC";
    int ucpc_pos = 0;
    string line;
    getline(cin, line);

    for (char ch : line) {
        if (ch == ucpc[ucpc_pos]) {
            if (++ucpc_pos == 4) {
                break;
            }
        }
    }

    if (ucpc_pos == 4) cout << "I love UCPC\n";
    else cout << "I hate UCPC\n";

    return 0;
}
