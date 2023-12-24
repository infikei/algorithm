// Solve 2023-02-04
// Update 2023-08-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Light{
    ll x, t, s;
    Light(ll x, ll t, ll s) : x(x), t(t), s(s) {}
    bool operator<(const Light &rhs) const {
        if (x != rhs.x) return x < rhs.x;
        if (t != rhs.t) return t < rhs.t;
        return s < rhs.s;
    }
};

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    vector<Light> lights;

    for (int i = 0; i < k; i++) {
        ll x, t, s;
        cin >> x >> t >> s;

        lights.push_back({ x, t, s });
    }

    sort(ALL(lights));

    ll now_t = 0, now_x = 0;

    for (Light light : lights) {
        now_t += light.x - now_x;
        now_x = light.x;

        ll t2 = light.t * 2;
        if ((now_t - light.s + t2) % t2 >= light.t) {
            now_t = ((now_t - light.s + t2) / t2) * t2 + light.s;
        }
    }

    now_t += n - now_x;

    cout << now_t << '\n';

    return 0;
}
