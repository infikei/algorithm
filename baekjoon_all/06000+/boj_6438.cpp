// Solve 2023-12-05

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

    for (int ti = 0; ti < t; ti++) {
        string sentence;
        getline(cin, sentence);
        reverse(sentence.begin(), sentence.end());
        cout << sentence << '\n';
    }

    return 0;
}
