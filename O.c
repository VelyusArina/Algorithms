#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef vector<int> EdgeVec;
typedef unordered_map<int, EdgeVec> Graph;
typedef vector<int> VisitedMap;

bool DFS_visit(int u, int color, Graph& graph, VisitedMap& visit) {
    visit[u] = color;
    for (int v : graph[u]) {
        if (visit[v] == 0) {
            if (!DFS_visit(v, 3 - color, graph, visit)) {
                return false;
            }
        }
        else if (visit[v] == visit[u]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    Graph graph;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    VisitedMap visit(n);
    bool is_bipartite = true;
    for (int i = 0; i < n && is_bipartite; i++) {
        if (!visit[i]) {
            bool result = DFS_visit(i, 1, graph, visit);
            is_bipartite = is_bipartite && result;
        }
    }
    for (int i = 0; i < n; i++) {
        if (visit[i] == 0) {
            is_bipartite = false;
            break;
        }
    }
    if (is_bipartite) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}
