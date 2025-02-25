// Solve 2025-02-25

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

    string message;
    getline(cin, message);

    int happy_cnt = 0;
    int sad_cnt = 0;

    for (int i = 3; i < SIZE(message); i++) {
        if (message[i - 3] == ':') {
            string w = message.substr(i - 2, 2);

            if (w == "-)") {
                happy_cnt++;
            }
            else if (w == "-(") {
                sad_cnt++;
            }
        }
    }

    if (happy_cnt == sad_cnt) {
        if (happy_cnt == 0) {
            cout << "none" << '\n';
        }
        else {
            cout << "unsure" << '\n';
        }
    }
    else if (happy_cnt > sad_cnt) {
        cout << "happy" << '\n';
    }
    else {
        cout << "sad" << '\n';
    }

    return 0;
}
