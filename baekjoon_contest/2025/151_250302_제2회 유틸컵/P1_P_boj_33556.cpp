// Solve 2025-03-02

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

bool equals_ignore_case(string &a, string &b) {
    if (SIZE(a) != SIZE(b)) {
        return false;
    }

    int len = SIZE(a);

    for (int i = 0; i < len; i++) {
        if (a[i] != b[i] && a[i] - 'a' != b[i] - 'A' && a[i] - 'A' != b[i] - 'a') {
            return false;
        }
    }

    return true;
}

int main() {
    FASTIO;

    string a, b;
    cin >> a >> b;

    if (a == "null") {
        cout << "NullPointerException" << '\n';
        cout << "NullPointerException" << '\n';
        return 0;
    }

    if (b == "null") {
        cout << "false" << '\n';
        cout << "false" << '\n';
        return 0;
    }

    if (a == b) {
        cout << "true" << '\n';
    }
    else {
        cout << "false" << '\n';
    }

    if (equals_ignore_case(a, b)) {
        cout << "true" << '\n';
    }
    else {
        cout << "false" << '\n';
    }

    return 0;
}
