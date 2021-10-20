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
};

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 4);
    g.addEdge(4, 3);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    g.print();
}
