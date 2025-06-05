// Solve 2025-06-02

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

    map<char, char> mp;

    string s = "aiyeou";

    for (int i = 0; i < 3; i++) {
        mp[s[i]] = s[i + 3];
        mp[s[i + 3]] = s[i];
        mp[s[i] - 'a' + 'A'] = s[i + 3] - 'a' + 'A';
        mp[s[i + 3] - 'a' + 'A'] = s[i] - 'a' + 'A';
    }

    s = "bkxznhdcwgpvjqtsrlmf";

    for (int i = 0; i < 10; i++) {
        mp[s[i]] = s[i + 10];
        mp[s[i + 10]] = s[i];
        mp[s[i] - 'a' + 'A'] = s[i + 10] - 'a' + 'A';
        mp[s[i + 10] - 'a' + 'A'] = s[i] - 'a' + 'A';
    }

    while (getline(cin, s)) {
        for (char& c : s) {
            if (mp.find(c) != mp.end()) {
                c = mp[c];
            }
        }

        cout << s << '\n';
    }

    return 0;
}
