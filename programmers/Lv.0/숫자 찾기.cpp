// Solve 2023-04-01

#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    string num_str = to_string(num);
    char k_char = '0' + k;
    int answer = -1;
    for (int i = 0; i < num_str.length(); i++) {
        if (num_str[i] == k_char) {
            answer = i + 1;
            break;
        }
    }

    return answer;
}
