// Solve 2025-05-11

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    FASTIO;

    string s;
    cin >> s;

    vector<pii> ans;
    int score = 0;

    for (char &c : s) {
        switch (c) {
            case '(':
                score++;
                break;

            case '{':
                score += 2;
                break;

            case '[':
                score += 3;
                break;

            case ')':
                score--;
                break;

            case '}':
                score -= 2;
                break;

            case ']':
                score -= 3;
                break;

            default:
                ans.emplace_back(score, c - '0');
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.back().first << '\n';

    return 0;
}
