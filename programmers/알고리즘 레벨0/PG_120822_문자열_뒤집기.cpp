// Solve 2023-03-19

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    string answer = "";

    answer = my_string;
    reverse(answer.begin(), answer.end());

    return answer;
}
