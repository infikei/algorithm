// Solve 2022-09-22
// Update 2023-08-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    while (true) {
        string s;
        getline(cin, s);

        if (s == "EOI") break;

        transform(s.begin(), s.end(), s.begin(), ::tolower);

        if (s.find("nemo") != string::npos) {
            cout << "Found\n";
        }
        else {
            cout << "Missing\n";
        }
    }

    return 0;
}
