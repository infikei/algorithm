#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int n;
    cin >> n;

    int game_time = 0, game_dt = 1;
    for (int i = 0; i < n; i++) {
        string card_type;
        int card_time;
        cin >> card_type >> card_time;

        game_time = (game_time + game_dt + 11) % 12 + 1;
        if (game_time != card_time && card_type == "HOURGLASS") game_dt *= -1;
        cout << game_time << (game_time == card_time && card_type != "HOURGLASS" ? " YES\n" : " NO\n");
    }

    return 0;
}