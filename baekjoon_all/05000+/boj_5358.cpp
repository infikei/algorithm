// Solve 2023-09-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string name;

    while (getline(cin, name)) {
        for (char &c : name) {
            if (c == 'i') cout << 'e';
            else if (c == 'e') cout << 'i';
            else if (c == 'I') cout << 'E';
            else if (c == 'E') cout << 'I';
            else cout << c;
        }

        cout << '\n';
    }

    return 0;
}
