// Solve 2023-10-01

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

    unordered_map<string, int> hs;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        hs[s] = i;
    }

    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        vec[i] = hs[s];
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vec[i] > vec[j]) {
                ans++;
                break;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
