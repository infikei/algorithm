// Solve 2023-03-25

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int n = numbers.size();
    int answer = 0;
    for (int i = 1; i < k; i++) {
        answer += 2;
        if (answer >= n) {
            answer -= n;
        }
    }
    answer = numbers[answer];

    return answer;
}
