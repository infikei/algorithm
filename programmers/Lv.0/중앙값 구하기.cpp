// Solve 2023-03-20

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;

    sort(array.begin(), array.end());
    answer = array[(int)array.size() / 2];

    return answer;
}
