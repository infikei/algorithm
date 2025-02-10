// Solve 2025-02-09

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

int sensors[10000];

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> sensors[i];
    }

    sort(sensors, sensors + n);

    priority_queue<int> pq;

    for (int i = 1; i < n; i++) {
        pq.push(sensors[i] - sensors[i - 1]);
    }

    int area = sensors[n - 1] - sensors[0];

    for (int i = 1; i < k && !pq.empty(); i++) {
        area -= pq.top();
        pq.pop();
    }

    println(area);

    return 0;
}
