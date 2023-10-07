// Solve 2023-10-06

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

    string ans;

    for (int i = 0, pos = 1; i < n; i++) {
        string word;
        cin >> word;

        if (pos > SIZE(word)) ans.push_back(' ');
        else ans.push_back(word[pos - 1]);

        pos = SIZE(word);
    }

    cout << ans << '\n';

    return 0;
}
