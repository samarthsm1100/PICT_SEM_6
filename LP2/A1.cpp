#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
struct Edge {
    int src, dest;
};
 
class Graph
{
public:
    vector<vector<int>> adjList;
 
     Graph(vector<Edge> const &edges, int n)
    {
        adjList.resize(n);
 
        for (auto &edge: edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};
 
void recursiveBFS(Graph const &graph, queue<int> &q, vector<bool> &discovered)
{
    if (q.empty()) {
        return;
    }
 
    int v = q.front();
    q.pop();
    cout << v << " ";
 
    for (int u: graph.adjList[v])
    {
        if (!discovered[u])
        {
            discovered[u] = true;
            q.push(u);
        }
    }
 
    recursiveBFS(graph, q, discovered);
}

void DFS(Graph const &graph, int v, vector<bool> &discovered2)
{
    discovered2[v] = true;
 
    cout << v << " ";
 
    for (int u: graph.adjList[v])
    {
        if (!discovered2[u]) {
            DFS(graph, u, discovered2);
        }
    }
}
 
int main()
{
    // vector<Edge> edges = {
    //     {1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
    //     {5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}
    // };
 
    // int n = 15;
 
    vector <Edge> edges;
    int n;

    cout << "Enter number of nodes : ";
    cin >> n;

    while(true){
        Edge e;
        cin>>e.src>>e.dest;
        edges.push_back(e);
        char c; cin>>c;
        if(c == 'N' || c == 'n'){
            break;
        }
    }

    Graph graph(edges, n);
 
    vector<bool> discovered(n, false);
 
    queue<int> q;
    
    cout << "BFS : ";
    for (int i = 0; i < n; i++)
    {
        if (discovered[i] == false)
        {
            discovered[i] = true;
 
            q.push(i);
 
            recursiveBFS(graph, q, discovered);
        }
    }
    cout << endl;

    vector<bool> discovered2(n, false);

    cout << "DFS : ";
    for (int i = 0; i < n; i++)
    {
        if (discovered2[i] == false) {
            DFS(graph, i, discovered2);
        }
    }
    cout << endl;
 
    return 0;
}

