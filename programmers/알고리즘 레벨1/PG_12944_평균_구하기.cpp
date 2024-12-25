// Solve 2023-03-21

#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    int sum_of_arr = 0;
    for (auto a : arr) {
        sum_of_arr += a;
    }

    double answer = (double)sum_of_arr / (double)arr.size();

    return answer;
}
