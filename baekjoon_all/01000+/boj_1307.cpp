// Solve 2025-02-13

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

void print_magic_square_odd(int n) {
    int n2 = n / 2;
    int n21 = n2 + 1;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            int u = (x + y + n21) % n;
            int v = (u + y + n21) % n;
            cout << (u * n + v + 1) << ' ';
        }

        cout << '\n';
    }
}

void print_magic_square_2(int n) {
    int n2 = n / 2;
    int n4 = n / 4;
    int n41 = n4 + 1;

    int c3 = n2 + n4 + 2;

    int kk = n2 * n2;
    int kk2 = kk * 2;
    int kk3 = kk * 3;

    for (int x = 0; x < n4; x++) {
        for (int y = 0; y < n; y++) {
            int u = (x + y + n41) % n2;
            int v = (u + y + n41) % n2;
            int prefix = (y < n4 ? kk3 : y < n2 ? 0 : y < c3 ? kk2 : kk);
            cout << (u * n2 + v + prefix + 1) << ' ';
        }

        cout << '\n';
    }

    for (int y = 0; y < n; y++) {
        int u = (n4 + y + n41) % n2;
        int v = (u + y + n41) % n2;
        int prefix = (y == 0 ? 0 : y <= n4 ? kk3 : y < n2 ? 0 : y < c3 ? kk2 : kk);
        cout << (u * n2 + v + prefix + 1) << ' ';
    }

    cout << '\n';

    for (int x = n4 + 1; x < n2; x++) {
        for (int y = 0; y < n; y++) {
            int u = (x + y + n41) % n2;
            int v = (u + y + n41) % n2;
            int prefix = (y < n4 ? kk3 : y < n2 ? 0 : y < c3 ? kk2 : kk);
            cout << (u * n2 + v + prefix + 1) << ' ';
        }

        cout << '\n';
    }

    for (int x = 0; x < n4; x++) {
        for (int y = 0; y < n; y++) {
            int u = (x + y + n41) % n2;
            int v = (u + y + n41) % n2;
            int prefix = (y < n4 ? 0 : y < n2 ? kk3 : y < c3 ? kk : kk2);
            cout << (u * n2 + v + prefix + 1) << ' ';
        }

        cout << '\n';
    }

    for (int y = 0; y < n; y++) {
        int u = (n4 + y + n41) % n2;
        int v = (u + y + n41) % n2;
        int prefix = (y == 0 ? kk3 : y <= n4 ? 0 : y < n2 ? kk3 : y < c3 ? kk : kk2);
        cout << (u * n2 + v + prefix + 1) << ' ';
    }

    cout << '\n';

    for (int x = n4 + 1; x < n2; x++) {
        for (int y = 0; y < n; y++) {
            int u = (x + y + n41) % n2;
            int v = (u + y + n41) % n2;
            int prefix = (y < n4 ? 0 : y < n2 ? kk3 : y < c3 ? kk : kk2);
            cout << (u * n2 + v + prefix + 1) << ' ';
        }

        cout << '\n';
    }
}

void print_magic_square_4(int n) {
    int nn1 = n * n + 1;
    int n2 = n / 2;
    int n4 = n / 4;
    int num = 0;

    for (int x = 0; x < n4; x++) {
        for (int y = 0; y < n4; y++) {
            cout << ++num << ' ';
        }

        for (int y = 0; y < n2; y++) {
            cout << nn1 - ++num << ' ';
        }

        for (int y = 0; y < n4; y++) {
            cout << ++num << ' ';
        }

        cout << '\n';
    }

    for (int x = 0; x < n2; x++) {
        for (int y = 0; y < n4; y++) {
            cout << nn1 - ++num << ' ';
        }

        for (int y = 0; y < n2; y++) {
            cout << ++num << ' ';
        }

        for (int y = 0; y < n4; y++) {
            cout << nn1 - ++num << ' ';
        }

        cout << '\n';
    }

    for (int x = 0; x < n4; x++) {
        for (int y = 0; y < n4; y++) {
            cout << ++num << ' ';
        }

        for (int y = 0; y < n2; y++) {
            cout << nn1 - ++num << ' ';
        }

        for (int y = 0; y < n4; y++) {
            cout << ++num << ' ';
        }

        cout << '\n';
    }
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    if (n % 2 == 1) {
        print_magic_square_odd(n);
    }
    else if (n % 4 == 0) {
        print_magic_square_4(n);
    }
    else {
        print_magic_square_2(n);
    }

    return 0;
}
