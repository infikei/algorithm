// Solve 2023-11-27

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
        string sentence;
        getline(cin, sentence);

        if (sentence.back() != '.') {
            sentence.push_back('.');
        }

        cout << sentence << '\n';
    }

    return 0;
}
