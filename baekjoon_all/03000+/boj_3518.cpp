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

    vector<string> article;
    string s;

    while (getline(cin, s)) {
        article.push_back(s);
    }

    vector<vector<string>> words;
    vector<int> word_lens;

    for (string& sentence : article) {
        vector<string> cur_words;
        stringstream ss(sentence);
        string w;
        int i = 0;

        while (getline(ss, w, ' ')) {
            if (w.empty()) continue;
            if (i >= word_lens.size()) word_lens.push_back(0);

            word_lens[i] = max(word_lens[i], (int) w.size());
            cur_words.push_back(w);
            i++;
        }

        words.push_back(cur_words);
    }

    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words[i].size(); j++) {
            if (j + 1 == words[i].size()) {
                cout << words[i][j] << '\n';
            }
            else {
                cout << words[i][j] << ' ';

                int iter = word_lens[j] - (int) words[i][j].size();

                while (iter-- > 0) cout << ' ';
            }
        }
    }

    return 0;
}
