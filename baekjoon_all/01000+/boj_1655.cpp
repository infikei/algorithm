// Solve 2022-07-28
// Update 2025-02-21

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    FASTIO;

    int n;
    cin >> n;

    priority_queue<int> pq_less;
    priority_queue<int, vector<int>, greater<int>> pq_greater;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        pq_less.push(x);

        if (SIZE(pq_less) - SIZE(pq_greater) >= 2) {
            pq_greater.push(pq_less.top());
            pq_less.pop();
        }

        if (!pq_greater.empty() && pq_less.top() > pq_greater.top()) {
            int x1 = pq_less.top();
            pq_less.pop();

            int x2 = pq_greater.top();
            pq_greater.pop();

            pq_greater.push(x1);
            pq_less.push(x2);
        }

        cout << pq_less.top() << '\n';
    }

    return 0;
}
