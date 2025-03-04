// Solve 2022-07-18
// Update 2025-03-04

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

bool is_java_var_name(string &var_name) {
    if (!islower(var_name[0])) {
        return false;
    }

    for (int i = 1; i < SIZE(var_name); i++) {
        if (var_name[i] == '_') {
            return false;
        }
    }

    return true;
}
bool is_cpp_var_name(string &var_name) {
    if (!islower(var_name[0])) {
        return false;
    }

    for (int i = 1; i < SIZE(var_name); i++) {
        if (isupper(var_name[i])) {
            return false;
        }
        else if (var_name[i] == '_') {
            if (i + 1 >= SIZE(var_name) || !islower(var_name[i + 1])) {
                return false;
            }
        }
    }

    return true;
}

string find_type_of_var_name(string &var_name) {
    if (is_java_var_name(var_name)) {
        return "java";
    }

    if (is_cpp_var_name(var_name)) {
        return "cpp";
    }

    return "error";
}

string convert_java_to_cpp_var_name(string &java_var_name) {
    string cpp_var_name;

    for (int i = 0; i < SIZE(java_var_name); i++) {
        if (java_var_name[i] <= 'Z') {
            cpp_var_name.push_back('_');
            cpp_var_name.push_back(java_var_name[i] - 'A' + 'a');
        }
        else {
            cpp_var_name.push_back(java_var_name[i]);
        }
    }

    return cpp_var_name;
}

string convert_cpp_to_java_var_name(string &cpp_var_name) {
    string java_var_name;
    int pos = 0;

    while (pos < SIZE(cpp_var_name)) {
        if (cpp_var_name[pos] == '_') {
            java_var_name.push_back(cpp_var_name[pos + 1] - 'a' + 'A');
            pos += 2;
        }
        else {
            java_var_name.push_back(cpp_var_name[pos]);
            pos++;
        }
    }

    return java_var_name;
}

int main() {
    FASTIO;

    string var_name;
    cin >> var_name;

    string var_name_type = find_type_of_var_name(var_name);

    if (var_name_type == "java") {
        cout << convert_java_to_cpp_var_name(var_name) << '\n';
    }
    else if (var_name_type == "cpp") {
        cout << convert_cpp_to_java_var_name(var_name) << '\n';
    }
    else {
        cout << "Error!" << '\n';
    }

    return 0;
}
