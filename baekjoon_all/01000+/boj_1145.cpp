// Solve 2022-11-07
// Update 2025-02-17

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

int get_gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int get_lcm(int a, int b) {
    return a / get_gcd(a, b) * b;
}

int main() {
    FASTIO;

    int nums[5];

    for (int i = 0; i < 5; i++) {
        cin >> nums[i];
    }

    int ans = 1000000;

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            int lcm2 = get_lcm(nums[i], nums[j]);

            for (int k = j + 1; k < 5; k++) {
                ans = min(ans, get_lcm(lcm2, nums[k]));
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
