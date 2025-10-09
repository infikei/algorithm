// Solve 2025-10-09

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

int main() {
    FASTIO;

    int n;
    cin >> n;
    map<string, int> st;

    while (n-- > 0) {
        string s;
        cin >> s;
        st[s]++;
    }

    vector<string> gene_1st;

    for (auto it = st.begin(); it != st.end(); it++) {
        gene_1st.push_back(it->first);

        if (it->second >= 2) {
            gene_1st.push_back(it->first);
        }
    }

    bool gene_2nd[26] = {false};

    for (int i = 0; i < size(gene_1st); i++) {
        for (int j = i + 1; j < size(gene_1st); j++) {
            gene_2nd[max(gene_1st[i][0], gene_1st[j][1]) - 'A'] = true;
            gene_2nd[max(gene_1st[i][1], gene_1st[j][0]) - 'A'] = true;
        }
    }

    int cnt = 0;

    for (int i = 0; i < 26; i++) {
        if (gene_2nd[i]) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    for (int i = 0; i < 26; i++) {
        if (gene_2nd[i]) {
            cout << (char) ('A' + i) << ' ';
        }
    }

    cout << '\n';
    return 0;
}
