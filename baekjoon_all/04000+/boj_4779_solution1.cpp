// Solve 2023-03-27

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

vector<string> cantor(int k) {
    if (k == 0) {
        return { " ", "-" };
    }

    vector<string> previous_cantor = cantor(k - 1);
    vector<string> res;
    res.push_back(previous_cantor[0] + previous_cantor[0] + previous_cantor[0]);
    res.push_back(previous_cantor[1] + previous_cantor[0] + previous_cantor[1]);
    return res;
}

int main() {
    FASTIO;

    int n;
    while (cin >> n) {
        cout << cantor(n)[1] << '\n';
    }

    return 0;
}
