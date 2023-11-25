// Solve 2023-11-25

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    vector<string> types = { "RCJA", "TFMN" };
    vector<int> scores(4, 0);

    for (int i = 0; i < (int)survey.size(); i++) {
        for (int type_idx = 0; type_idx < 4; type_idx++) {
            if (survey[i][0] == types[0][type_idx]) {
                scores[type_idx] += 4 - choices[i];
                break;
            }

            if (survey[i][1] == types[0][type_idx]) {
                scores[type_idx] += choices[i] - 4;
                break;
            }
        }
    }

    string answer = "";

    for (int type_idx = 0; type_idx < 4; type_idx++) {
        if (scores[type_idx] >= 0) answer.push_back(types[0][type_idx]);
        else answer.push_back(types[1][type_idx]);
    }

    return answer;
}
