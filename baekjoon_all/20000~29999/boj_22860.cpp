#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int name_sz, folder_tree_sz;
unordered_map<string, int> name_to_int;
vector<vector<int> > folder_tree;
vector<bool> is_folder;
unordered_set<int> file_cat;

vector<string> split(const string a, const char divider) {
    vector<string> res;
    string tmp = "";
    int a_size = a.length();

    for (int i = 0; i < a_size; i++) {
        if (a[i] == divider) {
            res.push_back(tmp);
            tmp = "";
        }
        else {
            tmp += a[i];
        }
    }
    res.push_back(tmp);

    return res;
}

int dfs(int idx = 0, bool init = true) {
    if (init) {
        file_cat.clear();
    }

    vector<int> now_folder = folder_tree[idx];
    int now_folder_size = now_folder.size();
    int res = 0;

    for (int i = 0; i < now_folder_size; i++) {
        if (is_folder[now_folder[i]]) {
            res += dfs(now_folder[i], false);
        }
        else {
            file_cat.insert(now_folder[i]);
            res += 1;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, M;
    cin >> N >> M;

    int parent_idx, child_idx, is_folder_input;
    string parent, child;

    for (int i = 0; i < N + M; i++) {
        cin >> parent >> child >> is_folder_input;

        if (name_to_int.find(parent) == name_to_int.end()) {
            name_to_int[parent] = name_sz;
            parent_idx = name_sz;
            name_sz++;

            is_folder.push_back(true);
        }
        else {
            parent_idx = name_to_int[parent];
        }

        if (name_to_int.find(child) == name_to_int.end()) {
            name_to_int[child] = name_sz;
            child_idx = name_sz;
            name_sz++;

            if (is_folder_input == 1) {
                is_folder.push_back(true);
            }
            else {
                is_folder.push_back(false);
            }
        }
        else {
            child_idx = name_to_int[child];
        }

        while (name_sz > folder_tree_sz) {
            folder_tree_sz++;
            folder_tree.push_back(vector<int>());
        }

        folder_tree[parent_idx].push_back(child_idx);
    }

    int Q;
    cin >> Q;

    string query;

    for (int q = 0; q < Q; q++) {
        cin >> query;
        vector<string> query_route = split(query, '/');

        int ans_cnt = dfs(name_to_int[query_route[query_route.size() - 1]]);
        int ans_cat = file_cat.size();
        cout << ans_cat << ' ' << ans_cnt << '\n';
    }

    return 0;
}