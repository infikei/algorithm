// Solve 2023-09-17
// Update 2023-12-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, d;
    cin >> n >> d;

    vector<string> graph(n);

    for (string &s : graph) {
        cin >> s;
    }

    if (d == 1) {
        for (string &s : graph) {
            for (char &c : s) {
                if (c == 'd') c = 'q';
                else if (c == 'b') c = 'p';
                else if (c == 'q') c = 'd';
                else if (c == 'p') c = 'b';
            }
        }
    }
    else {
        for (string &s : graph) {
            for (char &c : s) {
                if (c == 'd') c = 'b';
                else if (c == 'b') c = 'd';
                else if (c == 'q') c = 'p';
                else if (c == 'p') c = 'q';
            }
        }
    }

    for (string &s : graph) {
        cout << s << '\n';
    }

    return 0;
}
