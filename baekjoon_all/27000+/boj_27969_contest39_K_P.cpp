// Solve 2023-04-16
// Update 2025-02-26

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

    string line;
    getline(cin, line);

    stringstream ss(line);
    string w;
    int ason_size = 0;

    while (getline(ss, w, ' ')) {
        if (w[0] == '[' || isdigit(w[0])) {
            ason_size += 8;
        }
        else if (w[0] == ']') {
            continue;
        }
        else {
            ason_size += SIZE(w) + 12;
        }
    }

    cout << ason_size << '\n';

    return 0;
}
