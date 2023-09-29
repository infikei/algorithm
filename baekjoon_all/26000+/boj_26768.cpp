// Solve 2023-09-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string s;
    cin >> s;

    for (char &c : s) {
        if (c == 'a') c = '4';
        else if (c == 'e') c = '3';
        else if (c == 'i') c = '1';
        else if (c == 'o') c = '0';
        else if (c == 's') c = '5';
    }

    cout << s << '\n';

    return 0;
}
