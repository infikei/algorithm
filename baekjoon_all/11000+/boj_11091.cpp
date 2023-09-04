// Solve 2023-01-10
// Update 2023-09-03

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
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        bool check[26] = { false };

        for (const char c : line) {
            if (c >= 'a' && c <= 'z') check[c - 'a'] = true;
            else if (c >= 'A' && c <= 'Z') check[c - 'A'] = true;
        }

        string missing_alphabet = "";

        for (int i = 0; i < 26; i++) {
            if (!check[i]) missing_alphabet.push_back('a' + i);
        }

        if (missing_alphabet == "") {
            cout << "pangram\n";
        }
        else {
            cout << "missing " + missing_alphabet << '\n';
        }
    }

    return 0;
}
