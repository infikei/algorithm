// Solve 2025-03-30

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

string separator = ".|:#";

int main() {
    FASTIO;

    int n;
    string slogan;
    cin >> n >> slogan;

    vector<string> parts;
    parts.push_back(slogan);

    for (char &c : separator) {
        vector<string> new_parts;

        for (string &part : parts) {
            stringstream ss(part);
            string w;

            while (getline(ss, w, c)) {
                new_parts.push_back(w);
            }
        }

        swap(parts, new_parts);
    }

    int ans = 0;

    for (string &part : parts) {
        ans += stoi(part);
    }

    cout << ans << '\n';

    return 0;
}
