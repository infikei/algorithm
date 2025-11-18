// Solve 2022-11-26
// Update 2023-09-25

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

    unordered_set<string> rainbow_dance_hs;

    rainbow_dance_hs.insert("ChongChong");

    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;

        if (rainbow_dance_hs.find(a) != rainbow_dance_hs.end()) {
            rainbow_dance_hs.insert(b);
        }
        else if (rainbow_dance_hs.find(b) != rainbow_dance_hs.end()) {
            rainbow_dance_hs.insert(a);
        }
    }

    cout << SIZE(rainbow_dance_hs) << '\n';

    return 0;
}
