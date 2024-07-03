// Solve 2023-03-04

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

    string line;
    getline(cin, line);

    string ans;
    for (int i = 0; i < SIZE(line); i++) {
        char ch = line[i];
        if (ch == '(') {
            ans += " ( ";
        }
        else if (ch == ')') {
            ans += " ) ";
        }
        else if (ch == '<') {
            ans += " < ";
        }
        else if (ch == '>') {
            ans += " > ";
        }
        else if (ch == '&') {
            ans += " && ";
            i++;
        }
        else if (ch == '|') {
            ans += " || ";
            i++;
        }
        else {
            ans.push_back(ch);
        }
    }

    stringstream ss(ans);
    string word;
    while (getline(ss, word, ' ')) {
        if (word == "") continue;
        cout << word << ' ';
    }
    cout << '\n';

    return 0;
}