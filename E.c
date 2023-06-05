#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    int left = 0;
    int right = stalls[n - 1] - stalls[0];

    while (left <= right) {
        int mid = (left + right) / 2;

        int cows_placed = 1;
        int last_stall = stalls[0];

        for (int i = 1; i < n; i++) {
            if (stalls[i] - last_stall >= mid) {
                cows_placed++;
                last_stall = stalls[i];
            }
        }

        if (cows_placed >= k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << right << endl;
    return 0;
}