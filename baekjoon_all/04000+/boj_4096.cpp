// Solve 2025-05-30

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

    while (true) {
        string s;
        cin >> s;

        if (s == "0") break;

        int n = stoi(s);
        string s2 = s;

        for (int i = 0, j = s2.size() - 1; i < j; i++, j--) {
            s2[j] = s2[i];
        }

        int n2 = stoi(s2);

        if (n <= n2) {
            cout << n2 - n << '\n';
            continue;
        }

        int i = (s2.size() - 1) / 2;

        while (i >= 0) {
            if (s2[i] < '9') {
                s2[i]++;
                break;
            }

            s2[i] = '0';
            i--;
        }

        for (int i = 0, j = s2.size() - 1; i < j; i++, j--) {
            s2[j] = s2[i];
        }

        n2 = stoi(s2);
        cout << n2 - n << '\n';
    }

    return 0;
}
