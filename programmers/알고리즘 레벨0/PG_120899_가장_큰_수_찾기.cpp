// Solve 2023-03-31

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer = { array[0], 0 };

    for (int i = 1; i < array.size(); i++) {
        if (array[i] > answer[0]) {
            answer[0] = array[i];
            answer[1] = i;
        }
    }

    return answer;
}
