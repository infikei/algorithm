// Solve 2024-02-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;
    cin.ignore();

    for (int ti = 1; ti <= t; ti++) {
        string s;
        getline(cin, s);

        vector<string> words;
        stringstream ss(s);
        string w;

        while (getline(ss, w, ' ')) {
            words.push_back(w);
        }

        cout << "Case #" << ti << ':';

        for (auto it = words.rbegin(); it != words.rend(); it++) {
            cout << ' ' << *it;
        }

        cout << '\n';
    }

    return 0;
}
