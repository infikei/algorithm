#include <iostream>
#include <queue>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N;
queue<int> Q;

int main() {
    fastio;

    cin >> N;

    while (true) {
        int packet;
        cin >> packet;
        if (packet == -1) {
            break;
        }

        if (packet == 0) {
            Q.pop();
            continue;
        }

        if ((int)(Q.size()) < N) {
            Q.push(packet);
        }
    }

    if (Q.empty()) {
        cout << "empty\n";
    }
    else {
        while (!Q.empty()) {
            cout << Q.front() << ' ';
            Q.pop();
        }
    }

    return 0;
}