#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        string school_name, school_name_with_maxval;
        int school_val, school_maxval = -1;
        for (int n = 0; n < N; n++) {
            cin >> school_name >> school_val;
            if (school_val > school_maxval) {
                school_maxval = school_val;
                school_name_with_maxval = school_name;
            }
        }

        cout << school_name_with_maxval << '\n';
    }

    return 0;
}