// Solve 2023-10-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string document, word;
    getline(cin, document);
    getline(cin, word);

    int pos = 0, cnt = 0;

    while (pos + SIZE(word) <= SIZE(document)) {
        if (document.substr(pos, SIZE(word)) == word) {
            cnt++;
            pos += SIZE(word);
        }
        else {
            pos++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
