// Solve 2024-02-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Chat{
    string name, content;
};

int main() {
    FASTIO;

    int n;
    string winner_name, winner_content;
    cin >> n >> winner_name;

    Chat chatting[1000];

    for (Chat &chat : chatting) {
        cin >> chat.name >> chat.content;

        if (chat.name == winner_name) {
            winner_content = chat.content;
        }
    }

    int losers_count = 0;

    for (Chat &chat : chatting) {
        if (chat.name == winner_name) break;

        if (chat.content == winner_content) {
            losers_count++;
        }
    }

    cout << losers_count << '\n';

    return 0;
}
