#include<iostream>
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
    return 0;
}
