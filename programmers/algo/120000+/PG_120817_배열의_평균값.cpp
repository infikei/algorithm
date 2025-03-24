// Solve 2023-03-19

#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;

    int sum_of_numbers = 0;
    for (int num : numbers) {
        sum_of_numbers += num;
    }

    answer = sum_of_numbers;
    answer /= numbers.size();

    return answer;
}
