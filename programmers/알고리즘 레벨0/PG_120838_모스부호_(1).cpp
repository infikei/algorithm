// Solve 2023-03-24

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

string solution(string letter) {
    string answer = "";

    unordered_map<string, char> hs = { 
        {".-", 'a'}, {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'}, {".", 'e'}, {"..-.", 'f'}, {"--.", 'g'},
        {"....", 'h'}, {"..", 'i'}, {".---", 'j'}, {"-.-", 'k'}, {".-..", 'l'}, {"--", 'm'}, {"-.", 'n'},
        {"---", 'o'}, {".--.", 'p'}, {"--.-", 'q'}, {".-.", 'r'}, {"...", 's'}, {"-", 't'}, {"..-", 'u'},
        {"...-", 'v'}, {".--", 'w'}, {"-..-", 'x'}, {"-.--", 'y'}, {"--..", 'z'}
    };

    stringstream ss(letter);
    string s;
    while (ss >> s) {
        answer.push_back(hs[s]);
    }

    return answer;
}
