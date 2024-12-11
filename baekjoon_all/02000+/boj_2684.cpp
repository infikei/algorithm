// Solve 2024-12-10

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

string coin3[8] = {
    "TTT", "TTH", "THT", "THH",
    "HTT", "HTH", "HHT", "HHH"
};

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        string s;
        cin >> s;

        int cnt[8] = { 0 };

        for (int i = 0; i < 38; i++) {
            string w = s.substr(i, 3);

            for (int j = 0; j < 8; j++) {
                if (w == coin3[j]) {
                    cnt[j]++;
                    break;
                }
            }
        }

        for (int c : cnt) {
            printw(c);
        }

        cout << '\n';
    }

    return 0;
}
