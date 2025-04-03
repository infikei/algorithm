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

string solution(string &line) {
    stringstream ss(line);
    string w;
    vector<string> parts;

    while (getline(ss, w, ' ')) {
        if (!w.empty()) {
            parts.push_back(w);
        }
    }

    if (parts.size() != 1) {
        return "invalid input";
    }

    w = parts[0];

    for (char &c : w) {
        if (!isdigit(c)) {
            return "invalid input";
        }
    }

    int pos = 0;

    while (pos < w.size() - 1 && w[pos] == '0') {
        pos++;
    }

    return w.substr(pos);
}

int main() {
    FASTIO;

    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string line;
        getline(cin, line);

        cout << solution(line) << '\n';
    }

    return 0;
}
