// Solve 2023-08-30

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct File{
    int permission, user, group;
    File(int p = 0, int u = 0, int g = 0) : permission(p), user(u), group(g) {}
};

int main() {
    FASTIO;

    int u, f;
    cin >> u >> f;
    cin.ignore();

    unordered_map<string, int> group_hs;
    vector<set<int> > user_info;

    for (int i = 0; i < u; i++) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string user_name, group_name;
        int user, group;

        getline(ss, user_name, ' ');

        if (group_hs.find(user_name) == group_hs.end()) {
            user = SIZE(group_hs);
            group_hs[user_name] = user;
            user_info.push_back(set<int>());
        }
        else {
            user = group_hs[user_name];
        }

        user_info[user].insert(user);

        while (getline(ss, group_name, ',')) {
            if (group_hs.find(group_name) == group_hs.end()) {
                group = SIZE(group_hs);
                group_hs[group_name] = group;
                user_info.push_back(set<int>());
            }
            else {
                group = group_hs[group_name];
            }

            user_info[user].insert(group);
        }
    }

    unordered_map<string, int> file_hs;
    vector<File> file_info;

    for (int i = 0; i < f; i++) {
        string file_name, user_name, group_name;
        int permission;
        cin >> file_name >> permission >> user_name >> group_name;

        int file = SIZE(file_hs);
        file_hs[file_name] = file;
        file_info.emplace_back(permission, group_hs[user_name], group_hs[group_name]);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        string user_name, file_name;
        char operation_char;
        cin >> user_name >> file_name >> operation_char;

        int user = group_hs[user_name];
        File file = file_info[file_hs[file_name]];

        int operation;
        if (operation_char == 'X') operation = 1;
        else if (operation_char == 'W') operation = 2;
        else operation = 4;

        int ans = 0;

        if (user == file.user && (operation & (file.permission / 100)) != 0) {
            ans = 1;
        }
        else if (user_info[user].find(file.group) != user_info[user].end() && (operation & (file.permission / 10 % 10)) != 0) {
            ans = 1;
        }
        else if ((operation & (file.permission % 10)) != 0) {
            ans = 1;
        }

        cout << ans << '\n';
    }

    return 0;
}
