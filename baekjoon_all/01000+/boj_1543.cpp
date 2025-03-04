// Solve 2023-10-22
// Update 2025-03-04

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    FASTIO;

    string document, word;
    getline(cin, document);
    getline(cin, word);

    int pos = 0;
    int cnt = 0;

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
