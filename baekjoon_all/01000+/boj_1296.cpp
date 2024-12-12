// Solve 2024-12-12

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

int main() {
    FASTIO;

    string s;
    int n;
    cin >> s >> n;

    string love = "LOVE";
    int cnt[4] = { 0 };

    for (char c : s) {
        for (int i = 0; i < 4; i++) {
            if (c == love[i]) {
                cnt[i]++;
                break;
            }
        }
    }

    string max_team;
    int max_prob = -1;

    while (n-- > 0) {
        string t;
        cin >> t;

        int cnt2[4];

        for (int i = 0; i < 4; i++) {
            cnt2[i] = cnt[i];
        }

        for (char c : t) {
            for (int i = 0; i < 4; i++) {
                if (c == love[i]) {
                    cnt2[i]++;
                    break;
                }
            }
        }

        int prob = 1;

        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                prob = prob * (cnt2[i] + cnt2[j]) % 100;
            }
        }

        if (prob > max_prob) {
            max_prob = prob;
            max_team = t;
        }
        else if (prob == max_prob) {
            if (t < max_team) {
                max_team = t;
            }
        }
    }

    println(max_team);

    return 0;
}
