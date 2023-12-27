// Solve 2023-09-10
// Update 2023-12-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct cmp_study{
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

    vector<string> study;
    vector<int> boj_study;
    regex re("boj.kr/([0-9]+)");
    smatch match;

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        if (regex_match(s, match, re)) {
            boj_study.push_back(stoi(match[1]));
        }
        else {
            study.push_back(s);
        }
    }

    sort(study.begin(), study.end(), cmp_study());
    sort(boj_study.begin(), boj_study.end());

    for (string &s : study) {
        cout << s << '\n';
    }

    for (int &x : boj_study) {
        cout << "boj.kr/" << x << '\n';
    }

    return 0;
}
