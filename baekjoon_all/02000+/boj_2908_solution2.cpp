// Solve 2022-06-07
// Update 2023-08-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string a_str, b_str;
    cin >> a_str >> b_str;

    reverse(a_str.begin(), a_str.end());
    reverse(b_str.begin(), b_str.end());

    int a = stoi(a_str);
    int b = stoi(b_str);

    cout << max(a, b) << '\n';

    return 0;
}
