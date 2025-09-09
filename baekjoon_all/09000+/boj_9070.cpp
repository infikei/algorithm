// Solve 2025-09-09

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct Product{
    int weight;
    int cost;

    Product(int weight, int cost) : weight(weight), cost(cost) {
    }

    bool operator<(const Product& rhs) const {
        if (weight * rhs.cost != rhs.weight * cost) {
            return weight * rhs.cost < rhs.weight * cost;
        }

        return cost > rhs.cost;
    }
};

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        int w, c;
        cin >> w >> c;
        Product max_product(w, c);

        for (int i = 1; i < n; i++) {
            cin >> w >> c;
            Product cur_product(w, c);

            if (max_product < cur_product) {
                max_product = cur_product;
            }
        }

        cout << max_product.cost << '\n';
    }

    return 0;
}
