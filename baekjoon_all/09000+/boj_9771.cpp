// Solve 2023-12-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string word;
    getline(cin, word);

    string line;
    int cnt = 0;

    while (getline(cin, line)) {
        int pos = 0;

        while (pos + SIZE(word) <= SIZE(line)) {
            if (line.substr(pos, SIZE(word)) == word) {
                cnt++;
            }

            pos++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
