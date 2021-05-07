/*
Input:

15 16
0 3
0 2
0 4
2 3
2 8
3 1
4 5
5 6 
6 10
6 11
6 12
1 7
7 13 
7 14
14 9
8 9


output:

0 2 3 1 7 13 14 9 8 4 5 6 10 11 12 
0 2 3 4 8 1 5 9 7 6 14 13 10 11 12 
*/




#include<iostream>
#include<queue>
using namespace std;


void dfsPrint(int **arr, int numOfVertices, int *visited, int startingVertex){
    cout<<startingVertex<<" ";
    visited[startingVertex] = 1;
    for(int i=0; i<numOfVertices; i++){
        if(arr[startingVertex][i] == 1 and visited[i] == 0){
            dfsPrint(arr, numOfVertices, visited, i);
        }
    }
}

void bfsPrint(int **arr, int numOfVertices, int *visited, int startingVertex){
    queue<int> q; q.push(startingVertex); visited[startingVertex] =1;
    while(!q.empty()){
        for(int i=0; i<numOfVertices; i++){
            if(arr[startingVertex][i] == 1 and visited[i] == 0) {
                q.push(i); visited[i] = 1;
            }
        }
        cout<<q.front()<<" ";
        q.pop();
        startingVertex = q.front();
    }
}

int main(){
    int numOfVertices, numOfEdges;
    cin>>numOfVertices>>numOfEdges;
    int **arr = new int*[numOfVertices];
    for(int i=0; i<numOfVertices; i++){
        arr[i] = new int[numOfVertices];
        for(int j=0; j<numOfVertices; j++) arr[i][j] = 0;
    }

    for(int i=0; i<numOfEdges; i++){
        int point1, point2; cin>>point1>>point2;
        arr[point1][point2] = arr[point2][point1] = 1;
    }

    int visited[numOfVertices]; 
    for(int i=0; i<numOfVertices; i++) visited[i] = 0;

    int startingVertex = 0;
    dfsPrint(arr, numOfVertices, visited, startingVertex);
    cout<<endl;

    
   
    for(int i=0; i<numOfVertices; i++) visited[i] = 0;
    bfsPrint(arr, numOfVertices, visited, startingVertex);
    return 0;
}
