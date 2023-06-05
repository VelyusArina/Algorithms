#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> color;

void dfs(int v, vector<vector<int>> &g, int r) {
    color[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        if (color[i] == 0 && g[v][i] <= r && g[v][i] != 0) {
            dfs(i, g, r);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int left = graph[0][1];
    int right = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] > right) {
                right = graph[i][j];
            }
            if (graph[i][j] < left && i != left) {
                left = graph[i][j];
            }
        }
    }

    while (right - left > 1) {
        int mid = (right + left) / 2;

        color = vector<int>(n, 0);
        dfs(0, graph, mid);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (color[i] == 1) {
                count++;
            }
        }

        color = vector<int>(n, 0);
        vector<vector<int>> graph2(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph2[j][i] = graph[i][j];
            }
        }
        dfs(0, graph2, mid);
        for (int i = 0; i < n; i++) {
            if (color[i] == 1) {
                count++;
            }
        }

        if (count >= 2 * n) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << right;
    return 0;
}
