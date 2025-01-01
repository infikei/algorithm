// Solve 2024-12-31

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

int price[14];

int main() {
    FASTIO;

    int x;
    cin >> x;

    for (int i = 0; i < 14; i++) {
        cin >> price[i];
    }

    int money = x;
    int stock = 0;

    for (int i = 0; i < 14; i++) {
        int tmp = money / price[i];
        stock += tmp;
        money -= tmp * price[i];
    }

    int bnp = money + stock * price[13];

    money = x;
    stock = 0;
    int asc_or_desc = 0;

    for (int i = 1; i < 14; i++) {
        if (price[i - 1] < price[i]) {
            asc_or_desc = max(0, asc_or_desc) + 1;
        }
        else if (price[i - 1] > price[i]) {
            asc_or_desc = min(0, asc_or_desc) - 1;
        }
        else {
            asc_or_desc = 0;
        }

        if (asc_or_desc == 3) {
            money += stock * price[i];
            stock = 0;
        }
        else if (asc_or_desc <= -3) {
            int tmp = money / price[i];
            stock += tmp;
            money -= tmp * price[i];
        }
    }

    int timing = money + stock * price[13];

    println(bnp > timing ? "BNP" : bnp < timing ? "TIMING" : "SAMESAME");

    return 0;
}
