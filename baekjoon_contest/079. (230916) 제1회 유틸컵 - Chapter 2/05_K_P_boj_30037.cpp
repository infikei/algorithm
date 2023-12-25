// Solve 2023-09-17
// Update 2023-12-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        // 입력받은 문장을 공백으로 구분하여 나누기

        stringstream ss(line);
        string w;

        vector<string> words;

        while (getline(ss, w, ' ')) {
            words.push_back(w);
        }

        // 2번 규칙 적용하기

        vector<int> erase_idx;

        for (int i = 0, ie = SIZE(words) - 2; i < ie; i++) {
            if (words[i].back() < 'A' || words[i + 1] != "of") continue;

            string new_word;

            if (words[i + 2] == "Korea") {
                new_word = "K-" + words[i];
            }
            else if (words[i + 2] == "Korea.") {
                new_word = "K-" + words[i] + ".";
            }
            else if (words[i + 2] == "Korea,") {
                new_word = "K-" + words[i] + ",";
            }
            else if (words[i + 2] == "Korea?") {
                new_word = "K-" + words[i] + "?";
            }
            else if (words[i + 2] == "Korea!") {
                new_word = "K-" + words[i] + "!";
            }
            else continue;

            if (new_word[2] >= 'a') new_word[2] = new_word[2] - 'a' + 'A';

            erase_idx.push_back(i);
            erase_idx.push_back(i + 1);
            words[i + 2] = new_word;
            i++;
        }

        while (!erase_idx.empty()) {
            int pos = erase_idx.back();
            erase_idx.pop_back();
            words.erase(words.begin() + pos);
        }

        // 1번 규칙 적용하기

        for (int i = SIZE(words) - 2; i >= 0; i--) {
            if (words[i] != "Korea") continue;

            string new_word = "K-" + words[i + 1];

            if (new_word[2] >= 'a') new_word[2] = new_word[2] - 'a' + 'A';

            words[i] = new_word;
            words[i + 1] = "";
        }

        // 결과 출력하기

        for (string &w : words) {
            if (w.empty()) continue;

            cout << w << ' ';
        }

        cout << '\n';
    }

    return 0;
}
