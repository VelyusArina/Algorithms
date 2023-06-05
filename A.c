#include <iostream>

using namespace std;

int main() {
    int flowers;
    cin >> flowers;
    int *view = new int[flowers];
    for (int i = 0; i < flowers; i++) {
        cin >> view[i];
    }
    if (flowers <= 2) {
        cout << 1 << " " << flowers;
        return 0;
    }

    int bestLength = 2;
    int bestL = 0;
    int bestR = 1;
    int l = 0;
    for (int r = 2; r < flowers; r++) {
        int curFlower = view[r];

        if (curFlower == view[r - 1] && curFlower == view[r - 2]) {
            l = r - 1;
        }
        int curLength = r - l + 1;
        if (curLength > bestLength) {
            bestLength = curLength;
            bestL = l;
            bestR = r;
        }
    }

    cout << bestL + 1 << " " << bestR + 1;
}
