// Solve 2024-03-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

string s;

bool recur(int left, int right) {
    if (left == right) {
        return true;
    }

    int mid = (left + right) / 2;
    int i = left, j = right;

    while (i < j) {
        if (s[i] == s[j]) {
            return false;
        }

        i++; j--;
    }

    if (!recur(left, mid - 1)) {
        return false;
    }

    if (!recur(mid + 1, right)) {
        return false;
    }

    return true;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        cin >> s;

        cout << (recur(0, SIZE(s) - 1) ? "YES\n" : "NO\n");
    }

    return 0;
}
