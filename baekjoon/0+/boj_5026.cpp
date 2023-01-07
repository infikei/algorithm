#include <iostream>
#include <sstream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int calc(string s) {
    stringstream ss(s);
    string w;
    getline(ss, w, '+');
    int a = stoi(w);
    getline(ss, w);
    int b = stoi(w);
    return a + b;
}

int main() {
    fastio;

    int n;
    cin >> n;

    for (int nn = 0; nn < n; nn++) {
        string line;
        cin >> line;

        if (line == "P=NP") cout << "skipped\n";
        else cout << calc(line) << '\n';
    }

    return 0;
}