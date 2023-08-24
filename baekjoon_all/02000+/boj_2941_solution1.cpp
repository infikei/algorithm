// Solve 2022-06-07
// Update 2023-08-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string croatian_alphabets[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

    string word;
    cin >> word;

    for (const string &cro : croatian_alphabets) {
        while (true) {
            int idx = word.find(cro);
            if (idx == string::npos) break;

            word.replace(idx, SIZE(cro), "#");
        }
    }

    cout << SIZE(word) << '\n';

    return 0;
}
