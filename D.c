#include <iostream>

using namespace std;

int main() {
    int a,b,c,d,k;
    cin >> a >> b >> c >> d >> k;
    int start = a;
    for(int i = 0; i < k; i++){
        a = a * b;
        if (a < c) {
            cout << 0;
            return 0;
        } 
    	a = a - c;
        if (a >= d) {
            a = d;
            cout << d;
            return 0;
        }
        if(a == start){
            cout << start;
			return 0;       
        }
    }
    cout << a;
    return 0;
}