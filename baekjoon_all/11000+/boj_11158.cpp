// Solve 2025-04-03

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

    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string line;
        getline(cin, line);

        vector<string> words;
        stringstream ss(line);
        string w;

        while (getline(ss, w, ' ')) {
            words.push_back(w);
        }

        int ans = 0;

        for (int i = 0; i < words.size(); i++) {
            if (words[i] == "u" || words[i] == "ur") {
                ans++;
            }

            for (int j = 2; j < words[i].size(); j++) {
                if (words[i][j] == 'l' && words[i][j - 1] == 'o' && words[i][j - 2] == 'l') {
                    ans++;
                    break;
                }
            }
        }

        for (int i = 1; i < words.size(); i++) {
            if (words[i] == "of" && (words[i - 1] == "would" || words[i - 1] == "should")) {
                ans++;
            }
        }

        cout << ans * 10 << '\n';
    }

    return 0;
}
