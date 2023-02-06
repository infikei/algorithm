#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using pl3 = pair<ll, pll>;

int n, k;
vector<pl3> lights;

int main() {
    FASTIO;

    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        ll x, t, s;
        cin >> x >> t >> s;
        lights.push_back({x, {t, s}});
    }
    sort(ALL(lights));

    ll now_t = 0, now_x = 0;
    for (auto light : lights) {
        ll x = light.first;
        ll t = light.second.first;
        ll s = light.second.second;

        now_t += (x - now_x);
        now_x = x;

        ll t2 = t * 2;
        if ((now_t - s + t2) % t2 >= t) {
            now_t = ((now_t - s + t2) / t2) * t2 + s;
        }
    }
    now_t += (n - now_x);

    cout << now_t << '\n';

    return 0;
}