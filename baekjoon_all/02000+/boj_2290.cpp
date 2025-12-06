// Solve 2025-12-02

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

string digits[10][5] = {
    {" - ", "| |", "   ", "| |", " - "},
    {"   ", "  |", "   ", "  |", "   "},
    {" - ", "  |", " - ", "|  ", " - "},
    {" - ", "  |", " - ", "  |", " - "},
    {"   ", "| |", " - ", "  |", "   "},
    {" - ", "|  ", " - ", "  |", " - "},
    {" - ", "|  ", " - ", "| |", " - "},
    {" - ", "  |", "   ", "  |", "   "},
    {" - ", "| |", " - ", "| |", " - "},
    {" - ", "| |", " - ", "  |", " - "}
};

int main() {
    FASTIO;

    int s;
    string n;
    cin >> s >> n;

    vector<string> garo(5);

    for (char c : n) {
        for (int i = 0; i < 5; i++) {
            string digit = digits[c - '0'][i];
            garo[i].push_back(digit[0]);

            for (int j = 0; j < s; j++) {
                garo[i].push_back(digit[1]);
            }

            garo[i].push_back(digit[2]);
            garo[i].push_back(' ');
        }
    }

    cout << garo[0] << '\n';

    for (int i = 0; i < s; i++) {
        cout << garo[1] << '\n';
    }

    cout << garo[2] << '\n';

    for (int i = 0; i < s; i++) {
        cout << garo[3] << '\n';
    }

    cout << garo[4] << '\n';
    return 0;
}
