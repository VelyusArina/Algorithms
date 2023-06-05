#include <iostream>
#include <unordered_map>

using namespace std;

string line;
int equal_posit;
string operand1;
string operand2;

unordered_map<string, int> map;

bool is_number(string str) {
    int i = 0;
    if (str[i] == '-') i++;
    for (; i < str.length(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}


bool bracket_check(string symbol) {
    if (symbol[0] == '{' || symbol[0] == '}') {
        return true;
    } else {
        return false;
    }
}

bool open_bracket_check(string symbol) {
    if (symbol[0] == '{') {
        return true;
    } else {
        return false;
    }
}

int method() {
    unordered_map<string, int> cur_block;
    while (cin >> line) {
        if (!bracket_check(line)) {
            equal_posit = line.find('=');
            operand1 = line.substr(0, equal_posit);
            operand2 = line.substr(equal_posit + 1, line.length());
            if (!is_number(operand2)) {
                if (cur_block.find(operand1) == cur_block.cend()) {
                    cur_block[operand1] = map[operand1];
                }
                map[operand1] = map[operand2];
                cout << map[operand1] << '\n';
            } else {
                if (cur_block.find(operand1) == cur_block.cend()) {
                    cur_block[operand1] = map[operand1];
                }
                map[operand1] = stoi(operand2);
            }
        } else if (!open_bracket_check(line)) {
            for (const auto &i: cur_block) {
                map[i.first] = i.second;
            }
            cur_block.clear();
            return 0;
        } else {
            method();
        }
    }
}

int main() {
    method();
}
