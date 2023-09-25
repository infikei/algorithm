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

    vector<int> vec_p, vec_n;
    int cnt_zeros = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x > 0) vec_p.push_back(x);
        else if (x < 0) vec_n.push_back(x);
        else cnt_zeros++;
    }

    sort(vec_p.begin(), vec_p.end(), greater<int>());
    sort(vec_n.begin(), vec_n.end());

    deque<int> dque_p;

    if (!vec_p.empty()) dque_p.push_back(vec_p[0]);

    for (int i = 1, ie = SIZE(vec_p); i < ie; i++) {
        if (dque_p.front() <= dque_p.back()) {
            dque_p.push_back(vec_p[i]);
        }
        else {
            dque_p.push_front(vec_p[i]);
        }
    }

    if (!dque_p.empty() && dque_p.front() < dque_p.back()) {
        reverse(dque_p.begin(), dque_p.end());
    }

    deque<int> dque_n;

    if (!vec_n.empty()) dque_n.push_back(vec_n[0]);

    for (int i = 1, ie = SIZE(vec_n); i < ie; i++) {
        if (dque_n.front() > dque_n.back()) {
            dque_n.push_back(vec_n[i]);
        }
        else {
            dque_n.push_front(vec_n[i]);
        }
    }

    if (!dque_n.empty() && dque_n.front() < dque_n.back()) {
        reverse(dque_n.begin(), dque_n.end());
    }

    for (int &x : dque_p) {
        cout << x << ' ';
    }

    for (int i = 0; i < cnt_zeros; i++) {
        cout << 0 << ' ';
    }

    for (int &x : dque_n) {
        cout << x << ' ';
    }

    cout << '\n';

    return 0;
}
