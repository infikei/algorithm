// Solve 2023-07-01

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

    vector<int> vec;
    while (n > 0) {
        vec.push_back(n % 10);
        n /= 10;
    }

    vector<int> vec2, vec3;
    int a = 1;
    for (auto it = vec.begin(); it != vec.end(); it++) {
        a *= (*it);
        vec2.push_back(a);
    }
    a = 1;
    for (auto it = vec.rbegin(); it != vec.rend(); it++) {
        a *= (*it);
        vec3.push_back(a);
    }

    vec2.pop_back();
    reverse(vec2.begin(), vec2.end());
    vec3.pop_back();

    string ans = "NO\n";
    for (int i = 0, i_end = SIZE(vec2); i < i_end; i++) {
        if (vec2[i] == vec3[i]) {
            ans = "YES\n";
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}
