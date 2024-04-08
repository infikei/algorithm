// Solve 2024-04-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

bool prime_check[1000001];

int main() {
    FASTIO;

    for (int i = 2; i <= 1000000; i++) {
        prime_check[i] = true;
    }

    for (int i = 2; i <= 1000000; i++) {
        if (prime_check[i]) {
            for (int j = i + i; j <= 1000000; j += i) {
                prime_check[j] = false;
            }
        }
    }

    while (true) {
        int n;
        cin >> n;

        if (n == 0) break;

        int a = 3;
        int b = n - 3;

        while (a <= b) {
            if (prime_check[a] && prime_check[b]) {
                cout << n << " = " << a << " + " << b << '\n';
                break;
            }

            a += 2;
            b -= 2;
        }

        if (a > b) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }

    return 0;
}
