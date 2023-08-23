// Solve 2023-08-22

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

    int a[100000];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    deque<int> dq;

    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;

        if (a[i] == 0) dq.push_front(b);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;

        dq.push_back(c);
        cout << dq.front() << ' ';
        dq.pop_front();
    }

    cout << '\n';

    return 0;
}
