// Solve 2023-12-17

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int now_health = health;
    int t = 1;

    for (vector<int> &attack : attacks) {
        int dt = attack[0] - t;
        now_health += dt * bandage[1] + dt / bandage[0] * bandage[2];
        now_health = min(now_health, health);
        now_health -= attack[1];
        t = attack[0] + 1;

        if (now_health <= 0) {
            now_health = -1;
            break;
        }
    }

    return now_health;
}
