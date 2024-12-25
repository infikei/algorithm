// Solve 2023-03-30

#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int num1, int num2) {
    string answer = my_string;

    answer[num1] = my_string[num2];
    answer[num2] = my_string[num1];

    return answer;
}
