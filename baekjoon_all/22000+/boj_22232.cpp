// Solve 2022-08-20
// Update 2023-08-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct File{
    string name, ext;
    int flag;

    File(string file = "") : flag(0) {
        stringstream ss(file);
        getline(ss, name, '.');
        getline(ss, ext);
    }

    bool operator<(const File &rhs) const {
        if (name != rhs.name) return name < rhs.name;
        if (flag != rhs.flag) return flag > rhs.flag;
        return ext < rhs.ext;
    }
};

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<File> files;

    for (int i = 0; i < n; i++) {
        string file;
        cin >> file;

        files.emplace_back(file);
    }

    unordered_set<string> ext_hs;

    for (int i = 0; i < m; i++) {
        string ext;
        cin >> ext;

        ext_hs.insert(ext);
    }

    for (File &file : files) {
        if (ext_hs.find(file.ext) != ext_hs.end()) {
            file.flag = 1;
        }
    }

    sort(files.begin(), files.end());

    for (const File &file : files) {
        cout << file.name << '.' << file.ext << '\n';
    }

    return 0;
}
