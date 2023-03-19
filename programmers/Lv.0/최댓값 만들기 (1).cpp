// Solve 2023-03-19

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;

    int numbers_size = numbers.size();
    sort(numbers.begin(), numbers.end());
    answer = numbers[numbers_size - 1] * numbers[numbers_size - 2];

    return answer;
}
