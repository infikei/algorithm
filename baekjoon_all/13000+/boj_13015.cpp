// Solve 2023-02-15

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    string bar, middle, blank, left;
    bar.assign(n, '*');
    middle.assign(n * 2 - 3, ' ');
    blank.assign(n - 2, ' ');
    left = " ";

    cout << bar << middle << bar << '\n';
    for (int iter = n - 2; iter > 0; iter--) {
        middle.pop_back();
        middle.pop_back();
        cout << left << "*" << blank << "*" << middle << "*" << blank << "*" << '\n';
        left.push_back(' ');
    }
    cout << left << "*" << blank << "*" << blank << "*" << '\n';
    for (int iter = n - 2; iter > 0; iter--) {
        left.pop_back();
        cout << left << "*" << blank << "*" << middle << "*" << blank << "*" << '\n';
        middle.push_back(' ');
        middle.push_back(' ');
    }
    cout << bar << middle << bar << '\n';

    return 0;
}