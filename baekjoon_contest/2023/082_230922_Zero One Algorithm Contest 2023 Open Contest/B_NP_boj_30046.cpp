// Solve 2023-09-24
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

    int n;
    cin >> n;

    vector<string> hjses(3);

    for (string &hjs : hjses) {
        cin >> hjs;
    }

    bool ans = false;

    for (int h = 1; h <= 3; h++) {
        for (int j = 1; j <= 3; j++) {
            if (j == h) continue;

            for (int s = 1; s <= 3; s++) {
                if (s == h || s == j) continue;

                vector<string> changed_hjses = hjses;

                for (string &hjs : changed_hjses) {
                    for (char &c : hjs) {
                        if (c == 'H') c = '0' + h;
                        else if (c == 'J') c = '0' + j;
                        else if (c == 'S') c = '0' + s;
                    }
                }

                if (changed_hjses[0] < changed_hjses[1] && changed_hjses[1] < changed_hjses[2]) {
                    ans = true;
                }
            }
        }
    }

    cout << (ans ? "HJS! HJS! HJS!" : "Hmm...") << '\n';

    return 0;
}
