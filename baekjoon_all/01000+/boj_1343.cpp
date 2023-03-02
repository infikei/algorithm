// Solve 2023-03-02

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

    bool check = true;
    s.push_back('.');
    int i_end = SIZE(s), tmp = 0;
    for (int i = 0; i < i_end; i++) {
        if (s[i] == 'X') {
            tmp++;
            if (tmp == 4) {
                tmp = 0;
                s[i - 3] = s[i - 2] = s[i - 1] = s[i] = 'A';
            }
        }
        else {
            if (tmp == 2) {
                tmp = 0;
                s[i - 2] = s[i - 1] = 'B';
            }
            else if (tmp != 0) {
                check = false;
                break;
            }
        }
    }
    s.pop_back();

    if (check) {
        cout << s << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}