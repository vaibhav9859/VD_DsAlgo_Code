#include <bits/stdc++.h>
using namespace std;

class Graph{
    int v; list<int> *l;
public:
    Graph(int v){
        this -> v = v; l = new list<int>[v];
    }

    void addEdge(int x, int y, bool bidir=1){
        l[x].push_back(y); 
        if(bidir) l[y].push_back(x);
    }

    void print(){
        for(int i=0; i<v; i++){
            cout<<i<<"->";
            for(auto x : l[i]){
                cout<<x<<", ";
            }
            cout<<endl;
        }
    }

    void bfs(){
        vector<int> visited(v, 0);
        for(int i=0; i<v; i++){
            if(!visited[i]){
                queue<int> q;
                q.push(i); visited[i] = 1;
                while(!q.empty()){
                    int curEle = q.front();
                    q.pop();
                    for(auto node : l[curEle]){
                        if(!visited[node]){q.push(node); visited[node] = 1;}
                    }
                    cout<<curEle<<" ";
                }
            }
        }

    }
};

int main() {
    int v; cin>>v; int edges; cin>>edges;
    Graph g(v);

    for(int i=0; i<edges; i++){
        int x, y; cin>>x>>y;
        g.addEdge(x, y);
    }

    g.print();

    cout<<endl<<endl<<"Printing bfs"<<endl;
    g.bfs();
}
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int v; list<int> *l;
public:
    Graph(int v){
        this -> v = v; l = new list<int>[v];
    }

    void addEdge(int x, int y, bool bidir=1){
        l[x].push_back(y); 
        if(bidir) l[y].push_back(x);
    }

    void print(){
        for(int i=0; i<v; i++){
            cout<<i<<"->";
            for(auto x : l[i]){
                cout<<x<<", ";
            }
            cout<<endl;
        }
    }

    void bfs(){
        vector<int> visited(v, 0);
        for(int i=0; i<v; i++){
            if(!visited[i]){
                queue<int> q;
                q.push(i); visited[i] = 1;
                while(!q.empty()){
                    int curEle = q.front();
                    q.pop();
                    for(auto node : l[curEle]){
                        if(!visited[node]){q.push(node); visited[node] = 1;}
                    }
                    cout<<curEle<<" ";
                }
            }
        }

    }
};

int main() {
    int v; cin>>v; int edges; cin>>edges;
    Graph g(v);

    for(int i=0; i<edges; i++){
        int x, y; cin>>x>>y;
        g.addEdge(x, y);
    }

    g.print();

    cout<<endl<<endl<<"Printing bfs"<<endl;
    g.bfs();
}
