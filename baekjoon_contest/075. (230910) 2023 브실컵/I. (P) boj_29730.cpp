// Solve 2023-09-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct cmp_str{
    bool operator()(string &a, string &b) {
        if (SIZE(a) != SIZE(b)) return SIZE(a) < SIZE(b);
        return a < b;
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;
    cin.ignore();

    vector<string> vec;
    vector<int> boj_vec;

    regex re("boj.kr/([0-9]+)");
    smatch match;

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        if (regex_match(s, match, re)) {
            boj_vec.push_back(stoi(match[1]));
        }
        else {
            vec.push_back(s);
        }
    }

    sort(vec.begin(), vec.end(), cmp_str());
    sort(boj_vec.begin(), boj_vec.end());

    for (const string &s : vec) {
        cout << s << '\n';
    }

    for (const int &i : boj_vec) {
        cout << "boj.kr/" << i << '\n';
    }

    return 0;
}
