// Solve 2023-12-21
// Update 2025-09-10

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int MAX = 100; // main 코드는 O(N^3)이므로 빠른 테스트를 위해 1000 대신 100으로 설정
int MAX2 = MAX * 2;

string solution1_wrong(int a, int b) {
    string ret = "";

    for (int x = -MAX; x <= MAX; x++) {
        if (x * x + 2 * a * x + b == 0) {
            ret += to_string(x) + " ";
        }
    }

    return ret;
}

string solution2(int a, int b) {
    string ret = "";

    for (int x = -MAX2; x <= MAX2; x++) {
        if (x * x + 2 * a * x + b == 0) {
            ret += to_string(x) + " ";
        }
    }

    return ret;
}

string solution3(int a, int b) {
    string ret = "";

    int d = a * a - b;

    if (d >= 0) {
        int sqrt_d = sqrt(d);

        if (sqrt_d * sqrt_d == d) {
            int x1 = -a - sqrt_d;
            int x2 = -a + sqrt_d;

            if (x1 > x2) swap(x1, x2);

            ret += to_string(x1) + " ";

            if (x1 != x2) {
                ret += to_string(x2) + " ";
            }
        }
    }

    return ret;
}

int main() {
    FASTIO;

    cout << "### Solution2 VS Solution3 비교" << '\n';

    for (int a = -MAX; a <= MAX; a++) {
        for (int b = -MAX; b <= MAX; b++) {
            string ret1 = solution2(a, b);
            string ret2 = solution3(a, b);

            if (ret1 != ret2) {
                cout << "For a = " << a << ", b = " << b << "\n";
                cout << "    \"" << ret1 << "\"\n";
                cout << "    \"" << ret2 << "\"\n";
            }
        }
    }

    cout << "### Solution1 (wrong) VS Solution3 비교" << '\n';

    for (int a = -MAX; a <= MAX; a++) {
        for (int b = -MAX; b <= MAX; b++) {
            string ret1 = solution1_wrong(a, b);
            string ret2 = solution3(a, b);

            if (ret1 != ret2) {
                cout << "For a = " << a << ", b = " << b << "\n";
                cout << "    \"" << ret1 << "\"\n";
                cout << "    \"" << ret2 << "\"\n";
            }
        }
    }

    return 0;
}
