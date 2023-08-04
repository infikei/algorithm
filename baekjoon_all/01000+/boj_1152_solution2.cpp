// Solve 2022-06-05
// Update 2023-08-03

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string line;
    getline(cin, line);

    stringstream ss(line);
    string word;
    int ans = 0;
    while (getline(ss, word, ' ')) {
        if (word != "") {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
