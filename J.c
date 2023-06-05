#include <iostream>
#include <deque>
using namespace std;

int main() {
    int request, goblin;
    char sign;
    deque<int> dq1, dq2;
    cin >> request;
    for (int i = 0; i < request; i++) {
        cin >> sign ;
        if (sign == '+') {
            cin >> goblin;
            dq2.push_back(goblin);
            if (dq2.size() > dq1.size()) {
                dq1.push_back(dq2.front());
                dq2.pop_front();
            }
        } else if (sign == '*') {
            cin >> goblin;
            dq1.push_back(goblin);
            if (dq1.size() > dq2.size() + 1) {
                dq2.push_front(dq1.back());
                dq1.pop_back();
            }
        } else if (sign == '-') {
            cout << dq1.front() << endl;
            dq1.pop_front();
            if (dq2.size() > dq1.size()) {
                dq1.push_back(dq2.front());
                dq2.pop_front();
            }
        } else{
            return 0;
        }
    }
    return 0;
}