#include <bits/stdc++.h>
using namespace std;

class edge {
public:
    int src;
    int dest;

    edge(int s = 0, int d = 0) {
        src = s;
        dest = d;
    }
};

class graph {
public:
    map<int, list<int>> adjList;
    map<int, list<int>> bfsLevel;
    map<int, list<int>> dfsLevel;

    graph(vector<edge> edges) {
        for (auto e : edges) {
            adjList[e.src].push_back(e.dest);
            adjList[e.dest].push_back(e.src);
        }
    }

    void bfs(queue<pair<int, int>>& q, vector<bool>& discovered) {
        if (q.empty()) {
            return;
        }

        int front = q.front().first;
        int level = q.front().second;
        q.pop();
        
        cout << front << " ";

        bfsLevel[level].push_back(front);

        for (int i : adjList[front]) {
            if (!discovered[i]) {
                discovered[i] = true;
                q.push({i, level + 1});
            }
        }

        bfs(q, discovered);
    }

    void dfs(int v, vector<bool>& discovered, int level) {
        discovered[v] = true;
        dfsLevel[level].push_back(v);
        
        cout << v << " ";

        for (int u : adjList[v]) {
            if (!discovered[u]) {
                dfs(u, discovered, level + 1);
            }
        }
    }
};

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<edge> edges(m);
    cout << "Enter the source and destination nodes for each edge:\n";
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].src >> edges[i].dest;
    } cout << endl;

    graph* g = new graph(edges);

    vector<bool> discovered(n, false);
    queue<pair<int, int>> q;
    
    cout << "BFS Traversal : ";
    for (int i = 0; i < n; i++) {
        if (discovered[i] == false) {
            discovered[i] = true;
            q.push({i, 0});
            g->bfs(q, discovered);
        }
    } cout << endl;

    cout << "BFS Level Order Traversal: " << endl;
    for (auto level : g->bfsLevel) {
        cout << "Level " << level.first << ": ";
        for (auto node : level.second) {
            cout << node << " ";
        }
        cout << endl;
    }


    discovered.clear();
    discovered.resize(n, false);
    
    cout << endl << "DFS Traversal : ";
    for (int i = 0; i < n; i++) {
        if (!discovered[i]) {
            g->dfs(i, discovered, 0);
        }
    } cout << endl;

    cout << "DFS Level Order Traversal: " << endl;
    for (auto level : g->dfsLevel) {
        cout << "Level " << level.first << ": ";
        for (auto node : level.second) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
