// Solve 2023-03-25

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    int n = numbers.size();
    vector<int> answer(n, 0);

    if (direction == "left") {
        answer[n - 1] = numbers[0];
        for (int j = 1; j < n; j++) {
            answer[j - 1] = numbers[j];
        }
    }
    else {
        answer[0] = numbers[n - 1];
        for (int j = 1; j < n; j++) {
            answer[j] = numbers[j - 1];
        }
    }

    return answer;
}
