// Solve 2024-02-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct cmp_str{
    bool operator()(string a, string b) {
        if (SIZE(a) != SIZE(b)) return SIZE(a) < SIZE(b);
        return a < b;
    }
};

string convert_to_integer_format(string s) {
    int i = 0;

    while (i < SIZE(s) - 1 && s[i] == '0') {
        i++;
    }

    return s.substr(i);
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<string> numbers;

    while (n-- > 0) {
        string s;
        cin >> s;

        string cur_num;

        for (char c : s) {
            if (c >= '0' && c <= '9') {
                cur_num.push_back(c);
            }
            else {
                if (!cur_num.empty()) {
                    numbers.push_back(convert_to_integer_format(cur_num));
                    cur_num = "";
                }
            }
        }

        if (!cur_num.empty()) {
            numbers.push_back(convert_to_integer_format(cur_num));
        }
    }

    sort(numbers.begin(), numbers.end(), cmp_str());

    for (string num : numbers) {
        cout << num << '\n';
    }

    return 0;
}
