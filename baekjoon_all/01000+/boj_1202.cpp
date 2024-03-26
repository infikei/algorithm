// Solve 2024-03-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

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
    ll value_sum = 0;
    int ii = 0;

    for (int i = 0; i < k; i++) {
        int cur_capacity = capacity[i];

        while (ii < n && jewelry[ii].weight <= cur_capacity) {
            value_pq_maxtop.push(jewelry[ii++].value);
        }

        if (!value_pq_maxtop.empty()) {
            value_sum += value_pq_maxtop.top();
            value_pq_maxtop.pop();
        }
    }

    cout << value_sum << '\n';

    return 0;
}
