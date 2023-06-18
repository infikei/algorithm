// Solve 2023-06-17

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string s;
    cin >> s;

    if (s == "SONGDO") cout << "HIGHSCHOOL\n";
    else if (s == "CODE") cout << "MASTER\n";
    else if (s == "2023") cout << "0611\n";
    else if (s == "ALGORITHM") cout << "CONTEST\n";

    return 0;
}
