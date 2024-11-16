// Solve 2024-11-09

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

string solution(string s) {
    int plus = -1;

    for (int i = 0; i < size(s); i++) {
        if (s[i] == '+') {
            if (plus != -1) {
                return "No Money";
            }

            plus = i;
        }
    }

    if (plus == -1 || plus == 0 || plus == size(s) - 1) {
        return "No Money";
    }

    string a = s.substr(0, plus);
    string b = s.substr(plus + 1, size(s) - plus - 1);

    if (a != b) {
        return "No Money";
    }

    if (a[0] == '0') {
        return "No Money";
    }

    for (char c : a) {
        if (c < '0' || c > '9') {
            return "No Money";
        }
    }

    return "CUTE";
}

int main() {
    FASTIO;

    string s;
    cin >> s;

    println(solution(s));

    return 0;
}
