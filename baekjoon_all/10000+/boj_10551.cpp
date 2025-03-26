// Solve 2025-03-26

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

int conv[128];
string keyboard[8] = {
    "1QAZ",
    "2WSX",
    "3EDC",
    "4RFV5TGB",
    "6YHN7UJM",
    "8IK,",
    "9OL.",
    "0P;/-=[]'"
};

int main() {
    FASTIO;

    for (int i = 0; i < 8; i++) {
        for (char &c : keyboard[i]) {
            conv[c] = i;
        }
    }

    string s;
    cin >> s;

    int cnt[8] = { 0 };

    for (char &c : s) {
        cnt[conv[c]]++;
    }

    for (int i = 0; i < 8; i++) {
        cout << cnt[i] << '\n';
    }

    return 0;
}
