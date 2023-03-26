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

    string secured_name;
    cin >> secured_name;

    int diff = secured_name[1] - secured_name[0];
    if (diff < 0) {
        diff += 26;
    }
    if (diff == 16) {
        cout << "BHA\n";
    }
    else if (diff == 4) {
        cout << "KIS\n";
    }
    else {
        diff = secured_name[2] - secured_name[1];
        if (diff < 0) {
            diff += 26;
        }
        if (diff == 3) {
            cout << "NLCS\n";
        }
        else {
            cout << "SJA\n";
        }
    }

    return 0;
}
