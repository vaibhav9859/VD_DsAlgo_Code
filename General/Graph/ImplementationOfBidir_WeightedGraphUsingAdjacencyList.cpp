#include <bits/stdc++.h>
using namespace std;
class Graph{
    unordered_map< string, list< pair<string, int> > > adj_rep;
public:
    void addEdge(string x, string y, bool isBidir, int wt){
        adj_rep[x].push_back(make_pair(y, wt));
        if(isBidir){
            adj_rep[y].push_back(make_pair(x, wt));
        }
    }

    void printAdjList(){
        for(auto i = adj_rep.begin(); i != adj_rep.end(); i++){
            cout<<i->first<<": ";
            list< pair<string, int> > curList = i->second;
            for(auto j = curList.begin(); j != curList.end() ; j++){
                cout<<j->first<<" "<<j->second<<", ";
            }
            cout<<endl;
        }
    }
};

int main() {
    Graph g;

    g.addEdge("A", "B", true, 10);
    g.addEdge("B", "C", true, 20);
    g.addEdge("A", "C", false, 30);
    g.addEdge("A", "D", true, 40);
    g.addEdge("D", "C", true, 50);
    g.printAdjList();

    return 0;
}
