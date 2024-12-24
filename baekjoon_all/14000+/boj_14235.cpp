// Solve 2024-12-24

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

    int n;
    cin >> n;

    priority_queue<int> pq_maxtop;

    while (n-- > 0) {
        int a;
        cin >> a;

        if (a == 0) {
            if (pq_maxtop.empty()) {
                println(-1);
            }
            else {
                println(pq_maxtop.top());
                pq_maxtop.pop();
            }
        }
        else {
            for (int i = 0; i < a; i++) {
                int x;
                cin >> x;

                pq_maxtop.push(x);
            }
        }
    }

    return 0;
}
