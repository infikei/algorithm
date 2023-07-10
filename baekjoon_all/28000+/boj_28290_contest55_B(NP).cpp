// Solve 2023-07-10

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

    if (s == "fdsajkl;" || s == "jkl;fdsa") {
        cout << "in-out\n";
    }
    else if (s == "asdf;lkj" || s == ";lkjasdf") {
        cout << "out-in\n";
    }
    else if (s == "asdfjkl;") {
        cout << "stairs\n";
    }
    else if (s == ";lkjfdsa") {
        cout << "reverse\n";
    }
    else {
        cout << "molu\n";
    }

    return 0;
}
