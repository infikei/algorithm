// Solve 2025-01-10

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

string words[100];

bool is_palindrome(string &w) {
    int i = 0;
    int j = size(w) - 1;

    while (i < j) {
        if (w[i] != w[j]) {
            return false;
        }

        i++;
        j--;
    }

    return true;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int k;
        cin >> k;

        for (int i = 0; i < k; i++) {
            cin >> words[i];
        }

        string ans;

        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                string w = words[i] + words[j];

                if (is_palindrome(w)) {
                    ans = w;
                    break;
                }

                w = words[j] + words[i];

                if (is_palindrome(w)) {
                    ans = w;
                    break;
                }
            }

            if (!ans.empty()) break;
        }

        println(ans.empty() ? "0" : ans);
    }

    return 0;
}
