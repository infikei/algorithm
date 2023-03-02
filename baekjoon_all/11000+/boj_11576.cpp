// Solve 2023-03-02

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

    int a, b, m;
    cin >> a >> b >> m;

    int num = 0;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        num *= a;
        num += x;
    }

    stack<int> stck;
    while (num > 0) {
        stck.push(num % b);
        num /= b;
    }
    while (!stck.empty()) {
        cout << stck.top() << ' ';
        stck.pop();
    }
    cout << '\n';

    return 0;
}