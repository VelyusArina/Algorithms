#include <iostream>
#include <algorithm>
using namespace std;

int decrease(int const &i, int const &j) {
    return i > j;
}

int main() {
    int n, k;
    cin >> n >> k;
    int *price = new int [n];
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    sort(price, price + n, decrease);
    
    int sum, count = 0;
    for(int i = 0; i < n; i++){
        count++;
        if (count % k != 0) {
            sum = sum + price[i];
        }
    }
    cout << sum;
    return 0;
}
