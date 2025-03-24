// Solve 2023-03-26

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> box, int n) {
    int answer = 1;
    for (int i = 0; i < 3; i++) {
        answer *= box[i] / n;
    }

    return answer;
}
