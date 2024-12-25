// Solve 2023-03-29

#include <string>
#include <vector>

using namespace std;

string solution(string cipher, int code) {
    string answer = "";
    for (int i = code - 1; i < cipher.length(); i += code) {
        answer.push_back(cipher[i]);
    }

    return answer;
}
