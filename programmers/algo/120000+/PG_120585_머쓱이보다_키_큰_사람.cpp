// Solve 2023-03-19

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int height) {
    int answer = 0;

    sort(array.begin(), array.end());
    answer = upper_bound(array.begin(), array.end(), height) - array.begin();
    answer = (int)array.size() - answer;

    return answer;
}
