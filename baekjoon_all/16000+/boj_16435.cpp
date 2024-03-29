// Solve 2023-03-02
// Update 2024-02-13

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, l;
    cin >> n >> l;

    vector<int> heights(n);

    for (int &h : heights) {
        cin >> h;
    }

    sort(heights.begin(), heights.end());

    for (int &h : heights) {
        if (h <= l) {
            l++;
        } else {
            break;
        }
    }

    cout << l << '\n';

    return 0;
}
