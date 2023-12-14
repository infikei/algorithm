// Solve 2023-04-27
// Update 2023-12-14

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

    string re_input;
    cin >> re_input;

    regex re("(.*)\\*(.*)");
    smatch match;
    re_input = regex_replace(re_input, re, "$1.*$2");
    re.assign(re_input);

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        if (regex_match(name, match, re)) {
            cout << "DA\n";
        }
        else {
            cout << "NE\n";
        }
    }

    return 0;
}
