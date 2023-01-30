#include <iostream>
#include <string>
#include <unordered_map>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    unordered_map<string, string> hs;
    hs["CU"] = "see you";
    hs[":-)"] = "I’m happy";
    hs[":-("] = "I’m unhappy";
    hs[";-)"] = "wink";
    hs[":-P"] = "stick out my tongue";
    hs["(~.~)"] = "sleepy";
    hs["TA"] = "totally awesome";
    hs["CCC"] = "Canadian Computing Competition";
    hs["CUZ"] = "because";
    hs["TY"] = "thank-you";
    hs["YW"] = "you’re welcome";
    hs["TTYL"] = "talk to you later";

    while (true) {
        string line;
        cin >> line;
        if (hs.find(line) != hs.end()) cout << hs[line] << '\n';
        else cout << line << '\n';
        if (line == "TTYL") break;
    }

    return 0;
}