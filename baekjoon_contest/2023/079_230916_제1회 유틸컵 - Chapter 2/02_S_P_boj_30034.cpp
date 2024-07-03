// Solve 2023-09-16
// Update 2023-12-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    unordered_set<char> st;
    st.insert(' ');

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        st.insert(c);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        char c;
        cin >> c;
        st.insert(c);
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        char c;
        cin >> c;
        st.erase(c);
    }

    int line_len;
    cin >> line_len;
    cin.ignore();

    string line;
    getline(cin, line);

    vector<string> split_words;
    string cur_word;

    for (char c : line) {
        if (st.find(c) != st.end()) {
            if (!cur_word.empty()) {
                split_words.push_back(cur_word);
                cur_word = "";
            }
        }
        else {
            cur_word.push_back(c);
        }
    }

    if (!cur_word.empty()) {
        split_words.push_back(cur_word);
    }

    for (string &w : split_words) {
        cout << w << '\n';
    }

    return 0;
}
