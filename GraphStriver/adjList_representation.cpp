#include <iostream>
using namespace std;

int main() {
    //n is number of vertices
    //e is number of edges
    int n, e;
    cin>>n>>e;

    //below is implementation of a graph via adj list
    vector<int> adj[n+1];


    //Taking inputs and putting it into an adj list
    for(int i=0; i<e; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
