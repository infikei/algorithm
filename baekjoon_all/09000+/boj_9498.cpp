// Solve 2021-12-18
// Update 2023-02-22

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int score;
    cin >> score;

    if (score >= 90) {
        cout << "A\n";
    }
    else if (score >= 80) {
        cout << "B\n";
    }
    else if (score >= 70) {
        cout << "C\n";
    }
    else if (score >= 60) {
        cout << "D\n";
    }
    else {
        cout << "F\n";
    }

    return 0;
}