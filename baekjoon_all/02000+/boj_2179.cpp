// Solve 2025-10-05

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

string words[20001];

int main() {
    FASTIO;

    int n;
    cin >> n;
    map<string, int> mp;
    int max_prefix = 0;
    pii idx_of_max_prefix = {1, 2};

    for (int i = 1; i <= n; i++) {
        string word;
        cin >> word;
        words[i] = word;
        string prefix;

        for (int j = 0; j < size(word); j++) {
            prefix.push_back(word[j]);
            auto it = mp.find(prefix);

            if (it == mp.end()) {
                mp[prefix] = i;
            }
            else {
                if (size(prefix) > max_prefix) {
                    max_prefix = size(prefix);
                    idx_of_max_prefix = {it->second, i};
                }
                else if (size(prefix) == max_prefix) {
                    idx_of_max_prefix = min(idx_of_max_prefix, {it->second, i});
                }
            }
        }
    }

    int a = idx_of_max_prefix.first;
    int b = idx_of_max_prefix.second;
    cout << words[a] << '\n';
    cout << words[b] << '\n';
    return 0;
}
