// Solve 2024-03-04

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Par{
    int x, type;

    bool operator<(const Par &rhs) const {
        if (x != rhs.x) return x < rhs.x;
        return type < rhs.type;
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<Par> pars(n * 2);

    for (int i = 0; i < n * 2; i += 2) {
        int x, r;
        cin >> x >> r;
        pars[i].x = x - r;
        pars[i].type = 3;
        pars[i + 1].x = x + r;
        pars[i + 1].type = 1;
    }

    sort(pars.begin(), pars.end());
    stack<Par> stck;
    int ans = 1;

    for (Par par : pars) {
        if (par.type == 3) {
            stck.push(par);
        }
        else {
            int inner_len = 0;

            while (stck.top().type == 2) {
                inner_len += stck.top().x;
                stck.pop();
            }

            if (inner_len == par.x - stck.top().x) {
                ans++;
            }

            stck.top().type = 2;
            stck.top().x = par.x - stck.top().x;
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
