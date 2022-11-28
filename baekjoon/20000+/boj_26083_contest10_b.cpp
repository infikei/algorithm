#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N, today_date[3], target_date[3][3];
int transpose1[3] = {2, 1, 0};
int transpose2[3] = {1, 2, 0};

bool check_valid_date(int yy, int mm, int dd) {
    if (mm > 12 || mm == 0) {
        return false;
    }
    if (dd > 31 || dd == 0) {
        return false;
    }

    bool flag_feb29 = false;
    if (yy % 4 == 0) {
        flag_feb29 = true;
    }
    if (mm == 2) {
        if (flag_feb29 && dd > 29) {
            return false;
        }
        if (!flag_feb29 && dd > 28) {
            return false;
        }
    }
    else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
        if (dd == 31) {
            return false;
        }
    }

    return true;
}

int main() {
    fastio;

    for (int i = 0; i < 3; i++) {
        cin >> today_date[i];
    }
    cin >> N;

    for (int n = 0; n < N; n++) {
        for (int i = 0; i < 3; i++) {
            cin >> target_date[0][i];
            target_date[1][transpose1[i]] = target_date[0][i];
            target_date[2][transpose2[i]] = target_date[0][i];
        }

        bool check_date[3], check_all_date = false;
        for (int i = 0; i < 3; i++) {
            check_date[i] = check_valid_date(target_date[i][0], target_date[i][1], target_date[i][2]);
            if (check_date[i]) {
                check_all_date = true;
            }
        }
        if (!check_all_date) {
            cout << "invalid\n";
            continue;
        }

        int today_date_int = today_date[0] * 10000 + today_date[1] * 100 + today_date[2];
        bool flag_is_safe = true;
        for (int i = 0; i < 3; i++) {
            if (!check_date[i]) {
                continue;
            }
            int target_date_int = target_date[i][0] * 10000 + target_date[i][1] * 100 + target_date[i][2];
            if (today_date_int > target_date_int) {
                flag_is_safe = false;
                break;
            }
        }
        if (flag_is_safe) {
            cout << "safe\n";
        }
        else {
            cout << "unsafe\n";
        }
    }

    return 0;
}