// Solve 2023-11-24

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

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s == "Algorithm") cout << "204\n";
        else if (s == "DataAnalysis") cout << "207\n";
        else if (s == "ArtificialIntelligence") cout << "302\n";
        else if (s == "CyberSecurity") cout << "B101\n";
        else if (s == "Network") cout << "303\n";
        else if (s == "Startup") cout << "501\n";
        else if (s == "TestStrategy") cout << "105\n";
    }

    return 0;
}
