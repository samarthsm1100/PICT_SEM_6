#include <bits/stdc++.h>
using namespace std;

class edge{
    public:
    
    int src;
    int dest;
    
    edge(int s=0, int d=0){
        src = s;
        dest = d;
    }
};

class graph{
    public:
    
    vector<vector<int>> adjList;
    
    graph(vector<edge>edges, int n){
        adjList.resize(n);
        for(auto e:edges){
            adjList[e.src].push_back(e.dest);
            adjList[e.dest].push_back(e.src);
        }
    }
    
    void bfs(queue<int>&q, vector<bool>&discovered){
        // base case
        if(q.empty()){
            return;
        }
        
        int front = q.front();
        q.pop();
        cout << front << " ";
        
        for(int i : adjList[front]){
            if(!discovered[i]){
                discovered[i] = true;
                q.push(i);
            }
        }
        
        bfs(q, discovered);
    }
    
    void dfs(int v, vector<bool>&discovered){
        discovered[v] = true;
        cout << v << " ";
        for (int u: adjList[v]){
            if (!discovered[u]) {
                dfs(u, discovered);
            }
        }
    }
};



int main() {
    
    // vector<edge> edges = {
    //     {1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
    //     {5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}
    // };

    vector<edge> edges = {
        {0, 1}, {0, 2}, {0, 3}, {1, 4}, {2, 4}, {2, 6},
        {4, 7}, {4, 5}, {5, 6}
    };
    
    int n = 8;
    
    graph *g = new graph(edges, n);
    
    vector<bool>discovered(n,false);
    queue<int>q;
    
    for(int i=0; i<n; i++){
        if(discovered[i] == false){
            discovered[i] = true;
            q.push(i);
            g->bfs(q,discovered);
        }
    }
    
    cout << endl << endl;
    
    discovered.clear();
    discovered.resize(n,false);
    
    for(int i=0; i<n; i++){
        if(!discovered[i]){
            g->dfs(i,discovered);
        }
    }
    
    return 0;
}