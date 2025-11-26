// Solve 2025-11-24

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

// void precomputation() {
//     char conv[128];

//     for (char c = 'a'; c <= 'z'; c++) {
//         conv[c] = '?';
//     }

//     conv['q'] = 'z'; // 문제에서 주어짐

//     string s = "ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv";
//     string t = "ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup";

//     for (int i = 0; i < size(s); i++) {
//         conv[s[i]] = t[i];
//     }

//     for (char c = 'a'; c <= 'z'; c++) {
//         cout << c;
//     }

//     cout << '\n';

//     for (char c = 'a'; c <= 'z'; c++) {
//         cout << conv[c];
//     }

//     cout << '\n';
// }

int main() {
    FASTIO;

    string conv = "yhesocvxduiglbkrztnwjpfmaq";
    int t;
    cin >> t;
    cin.ignore();

    for (int ti = 1; ti <= t; ti++) {
        string s;
        getline(cin, s);

        for (char& c : s) {
            if (c == ' ') continue;

            c = conv[c - 'a'];
        }

        cout << "Case #" << ti << ": " << s << '\n';
    }

    return 0;
}
