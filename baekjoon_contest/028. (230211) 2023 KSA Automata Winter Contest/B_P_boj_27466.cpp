// Solve 2023-02-11
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

    int n, m;
    string s;
    cin >> n >> m >> s;

    string aeiou = "AEIOU";
    string t = s.substr(0, m - 3);
    int state = 0;

    for (int i = m - 3; i < n; i++) {
        if (state < 2) {
            if (s[i] == 'A') {
                t.push_back('A');
                state++;
            }
        }
        else if (state == 2) {
            bool is_aeiou = false;

            for (char &a : aeiou) {
                if (s[i] == a) {
                    is_aeiou = true;
                    break;
                }
            }

            if (!is_aeiou) {
                t.push_back(s[i]);
                state++;
            }
        }
        else {
            break;
        }
    }

    if (state < 3) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n" << t << '\n';
    }

    return 0;
}
