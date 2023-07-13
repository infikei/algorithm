// Solve 2022-06-03
// Update 2023-07-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

string dogam[100001];
unordered_map<string, int> hs;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    string s;

    for (int i = 1; i <= n; i++) {
        cin >> s;
        dogam[i] = s;
        hs[s] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> s;

        if (hs.find(s) == hs.end()) {
            cout << dogam[stoi(s)] << '\n';
        }
        else {
            cout << hs[s] << '\n';
        }
    }

    return 0;
}
