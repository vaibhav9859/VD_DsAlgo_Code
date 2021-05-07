/*
1. Here you need to consider that you need to print BFS path starting from vertex 0 only. 
2. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
3. E is the number of edges present in graph G.
4. Take graph input in the adjacency matrix.
5. Handle for Disconnected Graphs as well

The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains space separated two integers, that denote that there exists an edge between vertex a and b.

*/

#include <iostream>
#include <queue>
using namespace std;

void bfs(int **arr, int vertices, int startingVertex, int *visited){
    visited[startingVertex] = 1;
    queue<int> q; q.push(startingVertex);
    
    while(!q.empty()){
        for(int i=0; i<vertices; i++){
            if(arr[startingVertex][i] == 1 and visited[i] == 0){
                q.push(i); visited[i] = 1;
            }
        }
        cout<<startingVertex<<" ";
        q.pop();
        if(!q.empty()) startingVertex = q.front();
        else{
            for(int i=0; i<vertices; i++){
                if(visited[i] == 0){
                    startingVertex = i; q.push(i); visited[i] = 1; break;
                }
            }
        }
    }

}

int main() {
    // Write your code here
    int vertices, edges; cin>>vertices>>edges;
    if(vertices == 0) return 0;
    int **arr = new int*[vertices];
    for(int i=0; i<vertices; i++){
        arr[i] = new int[vertices];
        for(int j=0; j<vertices; j++){
            arr[i][j] = 0;
        }
    }
    
	for(int i=0; i<edges; i++){
        int startPoint, endPoint;
        cin>>startPoint>>endPoint;
        arr[startPoint][endPoint] = 1;
        arr[endPoint][startPoint] = 1;
    }    
    
    
    int visited[vertices];
    for(int i=0; i<vertices; i++) visited[i] = 0;
    bfs(arr, vertices, 0, visited);
    return 0;
}
