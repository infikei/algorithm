// Solve 2023-03-23

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<pair<int, int> > emergency_and_index;
    for (int i = 0; i < emergency.size(); i++) {
        emergency_and_index.push_back({ emergency[i], i });
    }
    sort(emergency_and_index.begin(), emergency_and_index.end(), greater<pair<int, int> >());

    vector<int> answer(emergency.size(), 0);
    for (int i = 0; i < emergency.size(); i++) {
        answer[emergency_and_index[i].second] = i + 1;
    }

    return answer;
}
