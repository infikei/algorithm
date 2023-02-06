#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    string KDA;
    cin >> KDA;

    stringstream ss(KDA);
    string KDAstr[3];
    int KDAint[3];

    for (int i = 0; i < 3; i++) {
        getline(ss, KDAstr[i], '/');
        KDAint[i] = stoi(KDAstr[i]);
    }

    if (KDAint[1] == 0 || KDAint[0] + KDAint[2] < KDAint[1]) {
        cout << "hasu\n";
    }
    else {
        cout << "gosu\n";
    }

    return 0;
}