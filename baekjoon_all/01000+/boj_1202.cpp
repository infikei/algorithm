// Solve 2024-03-25
// Update 2025-03-03

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

struct Jewelry{
    int weight, value;

    bool operator<(const Jewelry &rhs) const {
        return weight < rhs.weight;
    }
};

Jewelry jewelry[300000];
int capacity[300000];

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> jewelry[i].weight >> jewelry[i].value;
    }

    sort(jewelry, jewelry + n);

    for (int i = 0; i < k; i++) {
        cin >> capacity[i];
    }

    sort(capacity, capacity + k);

    priority_queue<int> value_pq_maxtop;
    ll max_value_sum = 0;
    int ii = 0;

    for (int i = 0; i < k; i++) {
        int cur_capacity = capacity[i];

        while (ii < n && jewelry[ii].weight <= cur_capacity) {
            value_pq_maxtop.push(jewelry[ii++].value);
        }

        if (!value_pq_maxtop.empty()) {
            max_value_sum += value_pq_maxtop.top();
            value_pq_maxtop.pop();
        }
    }

    cout << max_value_sum << '\n';

    return 0;
}
