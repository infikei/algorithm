// Solve 2023-09-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    unordered_map<string, char> hs = {
        { ".-" , 'A' },
        { "-..." , 'B' },
        { "-.-." , 'C' },
        { "-.." , 'D' },
        { "." , 'E' },
        { "..-." , 'F' },
        { "--." , 'G' },
        { "...." , 'H' },
        { ".." , 'I' },
        { ".---" , 'J' },
        { "-.-" , 'K' },
        { ".-.." , 'L' },
        { "--" , 'M' },
        { "-." , 'N' },
        { "---" , 'O' },
        { ".--." , 'P' },
        { "--.-" , 'Q' },
        { ".-." , 'R' },
        { "..." , 'S' },
        { "-" , 'T' },
        { "..-" , 'U' },
        { "...-" , 'V' },
        { ".--" , 'W' },
        { "-..-" , 'X' },
        { "-.--" , 'Y' },
        { "--.." , 'Z' },
        { ".----" , '1' },
        { "..---" , '2' },
        { "...--" , '3' },
        { "....-" , '4' },
        { "....." , '5' },
        { "-...." , '6' },
        { "--..." , '7' },
        { "---.." , '8' },
        { "----." , '9' },
        { "-----" , '0' },
        { "--..--" , ',' },
        { ".-.-.-" , '.' },
        { "..--.." , '?' },
        { "---..." , ':' },
        { "-....-" , '-' },
        { ".--.-." , '@' }
    };

    int n;
    cin >> n;

    string ans;

    for (int i = 0; i < n; i++) {
        string w;
        cin >> w;

        ans.push_back(hs[w]);
    }

    cout << ans << '\n';

    return 0;
}
