// Solve 2024-01-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct cmp_len{
    bool operator()(string a, string b) {
        if (SIZE(a) != SIZE(b)) {
            return SIZE(a) > SIZE(b);
        }

        return a > b;
    }
};

struct cmp_plus{
    bool operator()(string a, string b) {
        return a + b > b + a;
    }
};

int main() {
    FASTIO;

    int k, n;
    cin >> k >> n;

    vector<string> numbers(k);

    for (string &num : numbers) {
        cin >> num;
    }

    sort(numbers.begin(), numbers.end(), cmp_len());

    int iter = n - k;

    while (--iter >= 0) {
        numbers.push_back(numbers[0]);
    }

    sort(numbers.begin(), numbers.end(), cmp_plus());

    for (string &num : numbers) {
        cout << num;
    }

    cout << '\n';

    return 0;
}
