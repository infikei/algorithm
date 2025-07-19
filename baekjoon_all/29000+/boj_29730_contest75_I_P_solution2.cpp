// Solve 2023-09-10
// Update 2025-07-19

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

struct CmpLenAndDict{
    bool operator()(const string& s1, const string& s2) const {
        if (size(s1) != size(s2)) return size(s1) < size(s2);
        return s1 < s2;
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;
    cin.ignore();

    vector<int> boj_tasks;
    vector<string> tasks;

    while (n-- > 0) {
        string s;
        getline(cin, s);

        if (s.substr(0, 7) == "boj.kr/") {
            boj_tasks.push_back(stoi(s.substr(7)));
        }
        else {
            tasks.push_back(s);
        }
    }

    sort(tasks.begin(), tasks.end(), CmpLenAndDict());
    sort(boj_tasks.begin(), boj_tasks.end());

    for (string& s : tasks) {
        cout << s << '\n';
    }

    for (int& d : boj_tasks) {
        cout << "boj.kr/" << d << '\n';
    }

    return 0;
}
