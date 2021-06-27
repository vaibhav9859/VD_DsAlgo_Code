/*
Kruskal Algorithm
Date: 27 June 2021
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class edge{
public:
    int vOne;
    int vTwo;
    int w;
};

//Finding if the new edge will create cycle or not
bool edgeCreatingCycle(int v1, int v2, vector<int> &parent){
    int pOne = v1, pTwo = v2;
    while(parent[v1] != v1){
        v1 = parent[v1];
        pOne = v1;
    }
    
    while(parent[v2] != v2){
        v2 = parent[v2];
        pTwo = v2;
    }
    if(pOne == pTwo){
        return true;
    }
    else{
        parent[pOne] = pTwo;
        return false;
    }
}

class compareFunction{
public:
    bool operator()(edge const &x, edge const &y){
        return (x.w <= y.w);
    }
};

int main(){
    
    int v, numOfEdges; cin>>v>>numOfEdges;
    vector<edge> input;
    
    edge e;
    for(int i=0; i<numOfEdges; i++){
        int f, s, w; cin>>f>>s>>w;
        if(f<=s){
            e.vOne = f;
            e.vTwo = s;
            e.w = w;
        }
        else{
            e.vOne = s;
            e.vTwo = f;
            e.w = w;            
        }
        input.push_back(e);
    }
    
    //sort with respect to weights
    sort(input.begin(), input.end(), compareFunction());
    
    // for(int i=0; i<numOfEdges; i++){
    //     cout<<input[i].vOne<<" "<<input[i].vTwo<<" "<<input[i].w<<endl;
    // }
    // cout<<endl;
    
    
    //Time to make a parent vector and output vector
    vector<int> parent(v, 0); for(int i=0; i<v; i++) parent[i] = i;
    
    // for(int i=0; i<v; i++) cout<<parent[i]<<" ";
    // cout<<endl;
    
    
    //output Vector
    vector<edge> output;
    
    for(int i=0, j=0; i<v-1;){
        for(; j<numOfEdges; j++){
            if( edgeCreatingCycle(input[j].vOne, input[j].vTwo, parent) ){
                continue;
            }
            else{
                output.push_back(input[j]); j++; i++; break;
            }
        }
    }
    
    
    //Printing final output edges of MST
    for(int i=0; i<v-1; i++){
        cout<<output[i].vOne<<" "<<output[i].vTwo<<" "<<output[i].w<<endl;
    }
    cout<<endl;
    
    return 0;
}
