// Solve 2023-03-19

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;

    int n = common.size();
    if (common[0] + common[2] == common[1] * 2) {
        answer = common[n - 1] * 2 - common[n - 2];
    }
    else {
        answer = common[n - 1] * common[n - 1] / common[n - 2];
    }

    return answer;
}
