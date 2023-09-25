// Solve 2023-09-25

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

    vector<int> price(n);

    for (int &x : price) {
        cin >> x;
    }

    sort(price.begin(), price.end(), greater<int>());

    deque<int> dque;

    dque.push_back(price[0]);
    dque.push_back(price[1]);
    dque.push_front(price[2]);

    int ans = price[0] * (price[1] + price[2]);

    for (int i = 3; i < n; i++) {
        if (dque.front() <= dque.back()) {
            ans += dque.back() * price[i];
            dque.push_back(price[i]);
        }
        else {
            ans += dque.front() * price[i];
            dque.push_front(price[i]);
        }
    }

    ans += dque.front() * dque.back();

    cout << ans << '\n';

    for (int i = 0; i < n; i++) {
        cout << dque[i] << ' ';
    }

    cout << '\n';

    return 0;
}
