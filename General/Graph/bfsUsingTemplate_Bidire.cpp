#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

template<typename T>
class Graph{
    map<T, list<T> > adjList;
public:
    void addEdge(T x, T y){
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    void bfs(T src){
        map<T, bool> visited; 
        queue<T> q; q.push(src);
        while(!q.empty()){
            cout<<q.front()<<" ";
            list<T> cur_list = adjList[q.front()];
            q.pop(); visited[src] = true;
            for(auto i=cur_list.begin(); i != cur_list.end(); i++){
                if(!visited[*i]){
                    q.push(*i); visited[*i] = true;
                }
            }
        }
        cout<<endl;
    }
};

int main(){
    Graph<int> g;
    g.addEdge(1, 2); g.addEdge(2, 3); g.addEdge(3, 4); g.addEdge(1, 5); g.addEdge(4, 5);
    g.addEdge(4, 6); g.addEdge(4, 7); g.addEdge(6, 8); g.addEdge(6, 9); g.addEdge(5, 6);
    g.bfs(1);
    return 0;
}