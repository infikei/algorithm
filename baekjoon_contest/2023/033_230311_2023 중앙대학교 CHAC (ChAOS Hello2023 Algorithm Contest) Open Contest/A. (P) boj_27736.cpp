// Solve 2023-03-11

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

    int n;
    cin >> n;

    int vote[3] = { 0 };

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vote[x + 1]++;
    }

    if (vote[1] >= (n + 1) / 2) {
        cout << "INVALID\n";
    }
    else if (vote[2] > vote[0]) {
        cout << "APPROVED\n";
    }
    else {
        cout << "REJECTED\n";
    }

    return 0;
}