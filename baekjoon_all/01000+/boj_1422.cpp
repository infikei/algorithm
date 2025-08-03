// Solve 2024-01-14
// Update 2025-07-31

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

struct CmpLen{
    bool operator()(string a, string b) {
        if (size(a) != size(b)) {
            return size(a) > size(b);
        }

        return a > b;
    }
};

struct CmpPlus{
    bool operator()(string a, string b) {
        return a + b > b + a;
    }
};

int main() {
    FASTIO;

    int k, n;
    cin >> k >> n;
    vector<string> numbers(k);

    for (string& num : numbers) {
        cin >> num;
    }

    sort(numbers.begin(), numbers.end(), CmpLen());
    int iter = n - k;

    while (iter-- > 0) {
        numbers.push_back(numbers[0]);
    }

    sort(numbers.begin(), numbers.end(), CmpPlus());

    for (string& num : numbers) {
        cout << num;
    }

    cout << '\n';
    return 0;
}
