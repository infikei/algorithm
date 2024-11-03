// Solve 2024-11-02

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

    int n;
    string b1, k1, b2, k2;
    cin >> n >> b1 >> k1 >> b2 >> k2;

    string new_key;

    for (int i = 0; i < n; i++) {
        if (b1[i] == b2[i]) {
            if (k1[i] != k2[i]) {
                new_key = "htg!";
                break;
            }

            new_key.push_back(k1[i]);
        }
    }

    println(new_key);

    return 0;
}
