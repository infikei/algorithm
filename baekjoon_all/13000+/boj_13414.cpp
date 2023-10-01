// Solve 2023-10-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Student{
    int idx;
    string id;
    Student(int idx, string id) : idx(idx), id(id) {}
    bool operator<(const Student &rhs) const {
        return idx < rhs.idx;
    }
};

int main() {
    FASTIO;

    int k, l;
    cin >> k >> l;

    unordered_map<string, int> hs;

    for (int i = 1; i <= l; i++) {
        string id;
        cin >> id;

        hs[id] = i;
    }

    vector<Student> vec;

    for (auto it = hs.begin(); it != hs.end(); it++) {
        vec.emplace_back(it->second, it->first);
    }

    sort(vec.begin(), vec.end());

    for (int i = 0, ie = min(k, SIZE(vec)); i < ie; i++) {
        cout << vec[i].id << '\n';
    }

    return 0;
}
