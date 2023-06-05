#include <iostream>
#include <stack>

using namespace std;

stack<int> zoo_stack, animals_stack, traps_stack;

void delete_zoo(){
    zoo_stack.pop();
    animals_stack.pop();
    traps_stack.pop();
}

int main() {
    string zoo_str;
    cin >> zoo_str;
    int zoo[zoo_str.length() / 2];
    int animals = 0, trap = -1;
    const int bigLetter = 32;
    
    for (int i = 0; i < zoo_str.length(); i++) {
        (void)i;

        if(islower(zoo_str[i])){
            animals++;
            animals_stack.push(animals);
        }

        if (isupper(zoo_str[i])) {
            trap++;
            traps_stack.push(trap);
        }

        if (zoo_stack.size() != 0) {
            if ((zoo_stack.top() + bigLetter == int(zoo_str[i])) || (zoo_stack.top() == int(zoo_str[i]) + bigLetter)) {
                zoo[traps_stack.top()] = animals_stack.top();
                delete_zoo();
            } else zoo_stack.push(zoo_str[i]);
        } else zoo_stack.push(zoo_str[i]);
    }

    if (zoo_stack.size() == 0) {
        cout << "Possible \n";
        for (int i = 0; i < zoo_str.length() / 2; i++) {
            cout << zoo[i] << " ";
        }
    } else {
        cout << "Impossible";
    }
    return 0;
}
