// Solve 2023-03-29

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = array[0];
    for (int num : array) {
        if (abs(num - n) < abs(answer - n)) {
            answer = num;
        }
        else if (abs(num - n) == abs(answer - n) && num < answer) {
            answer = num;
        }
    }

    return answer;
}
