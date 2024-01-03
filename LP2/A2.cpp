#include <bits/stdc++.h>
using namespace std;

class Node{
    public:

    int f, g, h;

    Node(){
        f = g = h = 0;
    }
};

class Astar{
    public:

    priority_queue<Node, vector<Node>, greater<Node>> openlist;
    vector <Node> closedlist;

    Astar(Node start){
        openlist.push(start);
    }

    void func(){
        while(!openlist.empty()){

        }

    }
};

int main(){

    return 0;
}