#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int decrease(string const &i, string const &j) {
    return i + j > j + i ;
}

int main() {
    vector<string> numbers;
    string input, result;
    while (cin >> input) {
        numbers.push_back(input);
    }

    sort(numbers.begin(), numbers.end(), decrease);

    for (const auto& num : numbers) {
        result += num;
    }
    cout << result << endl;

    return 0;
}