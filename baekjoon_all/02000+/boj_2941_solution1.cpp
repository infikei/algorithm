// Solve 2022-06-07
// Update 2023-02-26

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

    string croatian_alphabets[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

    string word;
    cin >> word;

    for (auto cro : croatian_alphabets) {
        while (true) {
            int idx = word.find(cro);
            if (idx == string::npos) {
                break;
            }
            word.replace(idx, SIZE(cro), "#");
        }
    }

    cout << SIZE(word) << '\n';

    return 0;
}