// Solve 2023-09-17
// Update 2023-12-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int MAX = 1000;

vector<string> ans;
vector<bool> connect_mult;
vector<int> desc_type;
vector<string> desc;

void print_answer() {
    for (int i = 0; i <= MAX; i++) {
        cout << ans[i] << '\n';
    }
}

void print_for_test(int s, int e) {
    cout << "=== [print for test] ===\n";
    for (int i = s; i <= e; i++) {
        cout << i << " (" << SIZE(ans[i]) << ") : " << ans[i] << " (" << desc[i] << ")\n";
    }
}

void print_for_checking_if_more_than_75() {
    cout << "=== [print for checking if more than 75] ===\n";
    int cnt = 0;

    for (int i = 0; i <= MAX; i++) {
        if (SIZE(ans[i]) > 75) {
            cnt++;
            cout << i << " (" << SIZE(ans[i]) << ") : " << ans[i] << " (" << desc[i] << ")\n";
        }
    }

    cout << "Count : " << cnt << '\n';
}

void write_answer_as_file() {
    ofstream fout;
    fout.open("boj_18765.txt");

    for (int i = 0; i <= MAX; i++) {
        fout << ans[i] << '\n';
    }

    fout.close();
}

void update_1(bool init = false) {
    for (int n = 6; n <= MAX; n++) {
        // 방법 1.

        if (init) {
            ans[n] = ans[n - 1] + "+!![]";
            connect_mult[n] = false;
            desc_type[n] = 1;
            desc[n] = to_string(n - 1) + " + 1";
        }
        else {
            string new_ans = ans[n - 1] + "+!![]";

            if (SIZE(ans[n]) > SIZE(new_ans)) {
                ans[n] = new_ans;
                connect_mult[n] = false;
                desc_type[n] = 6;
                desc[n] = to_string(n - 1) + " + 1";
            }
        }

        // 방법 2.

        for (int i = 2, ie = sqrt(n); i <= ie; i++) {
            if (n % i != 0) continue;

            int ii = n / i;

            string left = ans[i];
            if (!connect_mult[i]) left = "[" + left + "]";

            string right = ans[ii];
            if (!connect_mult[ii]) right = "[" + right + "]";

            string new_ans = left + "*" + right;

            if (SIZE(ans[n]) >= SIZE(new_ans)) {
                ans[n] = new_ans;
                connect_mult[n] = true;
                desc_type[n] = 2;
                desc[n] = to_string(i) + " * " + to_string(ii);
            }
        }

        // 방법 3.

        if (n >= 10) {
            string new_ans = "+[";

            for (char c : to_string(n)) {
                new_ans += "[" + ans[c - '0'] + "]+";
            }

            new_ans.pop_back();
            new_ans.push_back(']');

            if (SIZE(ans[n]) >= SIZE(new_ans)) {
                ans[n] = new_ans;
                connect_mult[n] = true;
                desc_type[n] = 3;
                desc[n] = "char";
            }
        }
    }
}

void update_3() {
    for (int n = MAX - 1; n >= 6; n--) {
        string new_ans = ans[n + 1] + "-!![]";

        if (SIZE(ans[n]) > SIZE(new_ans)) {
            ans[n] = new_ans;
            connect_mult[n] = false;
            desc_type[n] = 4;
            desc[n] = to_string(n + 1) + " - 1";
        }

        int i = 1;

        while (true) {
            i++;
            int ii = n + i;
            if (ii > MAX) break;

            string left = ans[ii];
            string right = ans[i];

            if (desc_type[i] == 1) {
                int cur = 0;

                for (char &c : right) {
                    if (c == '[') cur++;
                    else if (c == ']') cur--;
                    else if (c == '+' && cur == 0) c = '-';
                }

                if (right[0] != '-') {
                    right = "-" + right;
                }
            }
            else if (desc_type[i] == 2 || desc_type[i] == 3) {
                if (right[0] == '+') right[0] = '-';
                else right = "-" + right;
            }
            else {
                break;
            }

            string new_ans = left + right;

            if (SIZE(ans[n]) > SIZE(new_ans)) {
                ans[n] = new_ans;
                connect_mult[n] = false;
                desc_type[n] = 5;
                desc[n] = to_string(ii) + " - " + to_string(i);
            }
        }
    }
}

int main() {
    FASTIO;

    ans.assign(MAX + 1, "");
    connect_mult.assign(MAX + 1, false);
    desc_type.assign(MAX + 1, 1);
    desc.assign(MAX + 1, "");

    ans[0] = "+[]";
    ans[1] = "+!![]";
    ans[2] = "!![]+!![]";

    for (int n = 3; n <= 5; n++) {
        ans[n] = ans[n - 1] + "+!![]";
        desc[n] = to_string(n - 1) + " + 1";
    }

    update_1(true);
    update_3();
    update_1();

    // print_answer();
    print_for_test(0, 12);
    print_for_checking_if_more_than_75();
    // write_answer_as_file();

    return 0;
}
