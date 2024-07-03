// Solve 2023-05-20

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

int fibonacci_seq[21];

void make_fibonacci_seq() {
    fibonacci_seq[1] = 1;
    fibonacci_seq[2] = 2;
    for (int i = 3; i <= 20; i++) {
        fibonacci_seq[i] = fibonacci_seq[i - 2] + fibonacci_seq[i - 1];
    }
}

int main() {
    FASTIO;

    make_fibonacci_seq();

    int n;
    string s;
    cin >> n >> s;

    int ans = 1;
    for (int i = 0; i < n - 3; i++) {
        int tmp = 0;
        while (i < n - 3 && s[i] == 'l' && s[i + 1] == 'o' && s[i + 2] == 'n' && s[i + 3] == 'g') {
            tmp++;
            i += 4;
        }
        if (tmp > 0) {
            ans *= fibonacci_seq[tmp];
        }
    }
    cout << ans << '\n';

    return 0;
}
