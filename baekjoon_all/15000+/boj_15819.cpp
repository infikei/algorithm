// Solve 2023-11-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, i;
    cin >> n >> i;

    vector<string> handles(n, "");

    for (int ni = 0; ni < n; ni++) {
        cin >> handles[ni];
    }

    sort(handles.begin(), handles.end());

    cout << handles[i - 1] << '\n';

    return 0;
}
