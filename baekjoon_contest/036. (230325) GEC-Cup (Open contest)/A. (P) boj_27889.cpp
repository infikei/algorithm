// Solve 2023-03-25

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    unordered_map<string, string> hs;
    hs["NLCS"] = "North London Collegiate School";
    hs["BHA"] = "Branksome Hall Asia";
    hs["KIS"] = "Korea International School";
    hs["SJA"] = "St. Johnsbury Academy";

    string short_name;
    cin >> short_name;
    cout << hs[short_name] << '\n';

    return 0;
}
