// Solve 2023-08-14

#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
    int answer = 1;

    if (my_string.size() < is_prefix.size()) {
        answer = 0;
    }
    else if (my_string.substr(0, (int)is_prefix.size()) != is_prefix) {
        answer = 0;
    }

    return answer;
}
