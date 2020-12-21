/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/
void dfs1(vector<int> g[], int N, vector<int> &visited, int vertex, vector<int> &output){
    if(visited[vertex] == -1){
        visited[vertex] = 1; output.push_back(vertex);
        for(int i=0; i<g[vertex].size(); i++){
            dfs1(g, N, visited,g[vertex][i], output);
        }
    }
}

vector <int> dfs(vector<int> g[], int N)
{
    vector<int> visited(N, -1); vector<int> output;
    dfs1(g, N, visited, 0, output);
    return output;

}