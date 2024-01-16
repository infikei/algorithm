// Solve 2024-01-15

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct cmp_plus{
    bool operator()(string a, string b) {
        return a + b > b + a;
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<string> numbers(n);
    bool flag_all_zero = true;

    for (string &num : numbers) {
        cin >> num;

        if (flag_all_zero && num != "0") {
            flag_all_zero = false;
        }
    }

    if (flag_all_zero) {
        cout << 0 << '\n';
    }
    else {
        sort(numbers.begin(), numbers.end(), cmp_plus());

        for (string &num : numbers) {
            cout << num;
        }

        cout << '\n';
    }

    return 0;
}
