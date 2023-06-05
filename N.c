#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> EdgeVec;
typedef vector<EdgeVec> Graph;
typedef vector<bool> VisitedMap;

void DFS_visit(const Graph & graph, VisitedMap & visit, int v) {
    visit[v] = true;
    for (int s : graph[v]) {
        if (!visit[s]) {
            DFS_visit(graph, visit, s);
        }
    }
}

int main() {
    int n;
    cin >> n;
    Graph graph(n);
    int i, j;
    for (i = 0; i < n; i++) {
        cin >> j;
        j -= 1;
        if (i != j) {
            graph[i].push_back(j);
            graph[j].push_back(i);
        }
    }
    VisitedMap visit(n, false);
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            DFS_visit(graph, visit, i);
            result++;
        }
    }
    cout << result;
    return 0;
}
