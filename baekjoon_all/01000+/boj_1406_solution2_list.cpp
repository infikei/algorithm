// Solve 2022-09-10
// Update 2023-03-17

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    string s;
    cin >> s;

    list<char> li(ALL(s));
    list<char>::iterator cur = li.end();

    int m;
    cin >> m;

    for (int mi = 0; mi < m; mi++) {
        char cmd;
        cin >> cmd;

        if (cmd == 'L') {
            if (cur != li.begin()) {
                cur--;
            }
        }
        else if (cmd == 'D') {
            if (cur != li.end()) {
                cur++;
            }
        }
        else if (cmd == 'B') {
            if (cur != li.begin()) {
                cur--;
                cur = li.erase(cur);
            }
        }
        else {
            char ch;
            cin >> ch;
            li.insert(cur, ch);
        }
    }

    for (list<char>::iterator it = li.begin(); it != li.end(); it++) {
        cout << *it;
    }
    cout << '\n';

    return 0;
}
