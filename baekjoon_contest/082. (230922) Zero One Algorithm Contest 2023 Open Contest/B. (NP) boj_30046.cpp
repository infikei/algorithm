// Solve 2023-09-24

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

    vector<string> hjs(3);

    for (string &s : hjs) {
        cin >> s;
    }

    bool ans = false;

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (j == i) continue;

            for (int k = 1; k <= 3; k++) {
                if (k == i || k == j) continue;

                vector<string> hjs2 = hjs;

                for (string &s : hjs2) {
                    for (char &c : s) {
                        if (c == 'H') c = '0' + i;
                        else if (c == 'J') c = '0' + j;
                        else if (c == 'S') c = '0' + k;
                    }
                }

                if (hjs2[0] < hjs2[1] && hjs2[1] < hjs2[2]) {
                    ans = true;
                }
            }
        }
    }

    if (ans) cout << "HJS! HJS! HJS!\n";
    else cout << "Hmm...\n";

    return 0;
}
