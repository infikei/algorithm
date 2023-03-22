// Solve 2023-03-21

#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int id_count = id_list.size();

    unordered_map<string, int> hs;
    for (int i = 0; i < id_count; i++) {
        hs[id_list[i]] = i;
    }

    unordered_map<string, set<string> > report_map;
    for (auto rep : report) {
        stringstream ss(rep);
        string from, to;
        ss >> from >> to;
        report_map[to].insert(from);
    }

    vector<int> answer(id_count, 0);
    for (auto it : report_map) {
        if (it.second.size() >= k) {
            for (auto it2 : it.second) {
                answer[hs[it2]]++;
            }
        }
    }

    return answer;
}
