// Solve 2025-02-04

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

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int candy_num, box_num;
        cin >> candy_num >> box_num;

        priority_queue<int> boxes;

        for (int i = 0; i < box_num; i++) {
            int r, c;
            cin >> r >> c;

            boxes.push(r * c);
        }

        int box_need = 0;

        while (candy_num > 0) {
            candy_num -= boxes.top();
            boxes.pop();
            box_need++;
        }

        println(box_need);
    }

    return 0;
}
