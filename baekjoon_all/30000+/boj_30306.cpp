// Solve 2023-12-23

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

    vector<int> dice1(n);

    for (int &d : dice1) {
        cin >> d;
    }

    vector<int> dice2(n);

    for (int &d : dice2) {
        cin >> d;
    }

    int cnt1 = 0;
    int cnt2 = 0;

    for (int &d1 : dice1) {
        for (int &d2 : dice2) {
            if (d1 > d2) cnt1++;
            else if (d1 < d2) cnt2++;
        }
    }

    if (cnt1 > cnt2) cout << "first\n";
    else if (cnt1 < cnt2) cout << "second\n";
    else cout << "tie\n";

    return 0;
}
