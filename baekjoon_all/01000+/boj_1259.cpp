// Solve 2023-03-20

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    while (true) {
        string num;
        cin >> num;
        if (num == "0") {
            break;
        }

        int num_size = SIZE(num);
        int i_end = num_size / 2;
        bool ans = true;
        for (int i = 0; i < i_end; i++) {
            if (num[i] != num[num_size - i - 1]) {
                ans = false;
                break;
            }
        }

        if (ans) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

    return 0;
}
