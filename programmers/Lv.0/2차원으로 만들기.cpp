// Solve 2023-03-25

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    for (int i = 0; i < num_list.size(); i += n) {
        vector<int> new_vec(num_list.begin() + i, num_list.begin() + (i + n));
        answer.push_back(new_vec);
    }

    return answer;
}
