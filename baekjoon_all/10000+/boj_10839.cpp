// Solve 2023-06-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Point{
    ll x, y;
    Point(ll nx = 0, ll ny = 0) : x(nx), y(ny) {}
    Point operator-(const Point &rhs) const {
        return { x - rhs.x, y - rhs.y };
    }
    bool operator<(const Point &rhs) const {
        if (x != rhs.x) {
            return x < rhs.x;
        }
        return y < rhs.y;
    }
};

int n, start, finish;
Point v[100001];
vector<int> ans;

ll calc_cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y;
}

int calc_ccw(const Point &a, const Point &b, const Point &c) {
    ll ccw = calc_cross(b - a, c - a);
    if (ccw > 0) return 1;
    if (ccw < 0) return -1;
    return 0;
}

void solve(int s, int e) {
    for (int i = s; i <= e; i++) {
        while (SIZE(ans) >= 2) {
            int back2 = ans.back();
            ans.pop_back();
            int back1 = ans.back();

            if (calc_ccw(v[back1], v[back2], v[i]) < 0) {
                ans.push_back(back2);
                break;
            }
        }
        ans.push_back(i);
    }
}

int main() {
    FASTIO;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
    }
    v[n] = v[0];
    cin >> start >> finish;

    if (start == 0) {
        solve(finish, n);
        ans.pop_back();
        ans.push_back(0);
        reverse(ans.begin(), ans.end());
    }
    else if (finish == 0) {
        solve(start, n);
        ans.pop_back();
        ans.push_back(0);
    }
    else if (start > finish) {
        solve(finish, start);
        reverse(ans.begin(), ans.end());
    }
    else solve(start, finish);

    cout << SIZE(ans) << '\n';
    for (auto &k : ans) {
        cout << k << ' ';
    }
    cout << '\n';

    return 0;
}
