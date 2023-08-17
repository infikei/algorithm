// Solve 2023-08-17

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
        string line;
        getline(cin, line);

        if (line.back() == '.') cout << "*Nod*" << endl;
        else if (line.back() == '?') cout << "Quack!" << endl;
        else break;
    }

    return 0;
}
