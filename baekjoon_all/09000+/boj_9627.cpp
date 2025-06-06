// Solve 2025-06-06

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

string num_words[20] = {
    "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

string num_words_with_step_10[10] = {
    "zero", "ten", "twenty", "thirty", "forty",
    "fifty", "sixty", "seventy", "eighty", "ninety"
};

string get_word_of_num(int num) {
    string res;

    if (num / 100 > 0) {
        res += num_words[num / 100] + "hundred";
    }

    num %= 100;

    if (num == 0) return res;
    if (num < 20) return res + num_words[num];

    res += num_words_with_step_10[num / 10];
    num %= 10;

    if (num == 0) return res;
    return res + num_words[num];
}

void print(vector<string>& words, string& num_word) {
    for (string& word : words) {
        if (word == "$") {
            cout << num_word << ' ';
        }
        else {
            cout << word << ' ';
        }
    }

    cout << '\n';
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<string> words(n);
    int sentence_len = 0;

    for (string& word : words) {
        cin >> word;
        sentence_len += word.size();
    }

    sentence_len--;

    for (int num = 1; num <= 999; num++) {
        string num_word = get_word_of_num(num);

        if (sentence_len + num_word.size() == num) {
            print(words, num_word);
            return 0;
        }
    }

    return 0;
}
