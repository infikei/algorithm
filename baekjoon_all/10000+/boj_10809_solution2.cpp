// Solve 2022-06-05
// Update 2023-12-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string word;
    cin >> word;

    for (char ch = 'a'; ch <= 'z'; ch++) {
        int pos = word.find(ch);

        cout << pos << ' ';
    }

    cout << '\n';

    return 0;
}
