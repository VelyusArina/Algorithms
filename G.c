#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> c(26);

void input(){
    for (int i = 0; i < 26; i++) {
        cin >> c[i];
    }
}

bool decrease(char const &i, char const &j) {
    if (c[i - 'a'] == c[j - 'a']) {
        return i < j;
    }
    return c[i - 'a'] > c[j - 'a'];
}


int main() {
    string input_string;
    cin >> input_string;

    input();

    vector<int> count(26);
    for (char ch : input_string) {
        count[ch - 'a']++;
    }

    sort(input_string.begin(), input_string.end(), decrease);

    string rep_letters, com_letters;
    for (int i = 0; i < input_string.size() - 1; i++) {
        if (input_string[i] == input_string[i + 1] && (rep_letters.size() == 0 || (rep_letters.size() != 0 && rep_letters[rep_letters.size() - 1] != input_string[i]))) {
            rep_letters.push_back(input_string[i]);
            i++;
        } else {
            com_letters.push_back(input_string[i]);
        }
    }

    if (input_string.size() >  2 * rep_letters.size() + com_letters.size()) {
        com_letters.push_back(input_string[input_string.size() - 1]);
    }

    string result = rep_letters + com_letters;
    reverse(rep_letters.begin(), rep_letters.end());
    result += rep_letters;

    cout << result;  //slurkhels

    return 0;
}