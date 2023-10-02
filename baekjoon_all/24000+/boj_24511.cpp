// Solve 2023-08-22
// Update 2023-10-02

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

    int que_or_stck[100000];

    for (int i = 0; i < n; i++) {
        cin >> que_or_stck[i];
    }

    deque<int> dque;

    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;

        if (que_or_stck[i] == 0) dque.push_back(b);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;

        dque.push_front(c);
        cout << dque.back() << ' ';
        dque.pop_back();
    }

    cout << '\n';

    return 0;
}
