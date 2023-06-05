#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int *number {new int[N]};
    for(int i = 0; i < N; i++) {
        cin >> number[i];
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>,
    greater<pair<int, int>>> heap;
    for(int i=0; i < K; i++) {
        heap.push(make_pair(number[i], i));
    }
    string result = to_string(heap.top().first);

    for(int i = K; i < N; i++) {
        heap.push(make_pair(number[i], i));
        while(heap.top().second <= i-K) {
            heap.pop();
        }

        result += " "  + to_string(heap.top().first) ;
    }
    cout << result;
    return 0;
}