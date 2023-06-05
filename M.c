#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Node {
public:
    int x, y;

    Node() : x(0), y(0) {}

    Node(int _x, int _y) : x(_x), y(_y) {}

    bool operator==(const Node& cmp) const {
        return x == cmp.x && y == cmp.y;
    }

    bool operator!=(const Node& cmp) const {
        return x != cmp.x || y != cmp.y;
    }

    Node operator+(const Node& value) const {
        return Node(x + value.x, y + value.y);
    }

    Node operator-(const Node& value) const {
        return Node(x - value.x, y - value.y);
    }
};

bool inField(int n, int m, const Node& node) {
    return (node.x >= 0 && node.x < n) && (node.y >= 0 && node.y < m);
}

int main() {
    int n, m;
    cin >> n >> m;

    Node start, end;
    cin >> start.x >> start.y >> end.x >> end.y;

    start.x--, start.y--;
    end.x--, end.y--;

    vector<string> f(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }

    const Node ways[4] = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
    };

    queue<Node> q;
    q.push(start);
    vector<vector<int>> d(n,vector<int>(m, 0));
    vector<vector<Node>> p(n, vector<Node>(m));
    vector<vector<bool>> used(n, vector<bool>(m, false));

    used[start.x][start.y] = true;
    p[start.x][start.y] = { -1, -1 };

    while (!q.empty()) {
        Node v = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            Node to = v + ways[i];

            if (inField(n, m, to) && f[to.x][to.y] != '#') {
                int cost = (f[to.x][to.y] == '.' ? 1 : 2);

                if (!used[to.x][to.y] || d[to.x][to.y] > d[v.x][v.y] + cost) {
                    used[to.x][to.y] = true;
                    q.push(to);
                    d[to.x][to.y] = d[v.x][v.y] + cost;
                    p[to.x][to.y] = v;
                }
            }
        }
    }

    string line;

    if (d[end.x][end.y] != 0) {
        Node anEnd = end;

        while (anEnd != start) {
            Node t = anEnd;
            anEnd = p[anEnd.x][anEnd.y];
            Node diff = anEnd - t;

            switch (diff.x) {
                case 1:
                    line.push_back('N');
                    break;
                case -1:
                    line.push_back('S');
                    break;
                default:
                    switch (diff.y) {
                        case 1:
                            line.push_back('W');
                            break;
                        case -1:
                            line.push_back('E');
                            break;
                        default:
                            break;
                    }
                    break;
            }
        }

        reverse(line.begin(), line.end());
        cout << d[end.x][end.y] << '\n';
        cout << line << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}
