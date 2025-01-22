// Solve 2025-01-21

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

int score[1000001];

int main() {
    FASTIO;

    int l;
    cin >> l;

    for (int i = 1; i <= l; i++) {
        cin >> score[i];
    }

    ll max_score_sum = 0;
    int d_when_max_score_sum = 1;

    for (int i = 1; i <= l; i++) {
        max_score_sum += score[i];
    }

    for (int d = 2; d <= l; d++) {
        ll cur_score_sum = 0;

        for (int i = d; i <= l; i += d) {
            cur_score_sum += score[i];
        }

        if (cur_score_sum > max_score_sum) {
            max_score_sum = cur_score_sum;
            d_when_max_score_sum = d;
        }
    }

    if (max_score_sum <= 0) {
        println("0 0");
    }
    else {
        printw(d_when_max_score_sum);
        println(max_score_sum);
    }

    return 0;
}
