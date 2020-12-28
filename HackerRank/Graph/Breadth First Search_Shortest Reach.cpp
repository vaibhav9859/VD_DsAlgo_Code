vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    map<int, list<int>> ad_list;
    for(int i=0; i<edges.size(); i++){
        ad_list[edges[i][0]].push_back(edges[i][1]);
        ad_list[edges[i][1]].push_back(edges[i][0]);
    }
    
    vector<int> visited(n+1, INT_MAX); visited[s] = 0;
    queue<int> q; q.push(s); vector<int> output;
   
     while(!q.empty()){
        int x = q.front();
        q.pop();
        list<int> curList = ad_list[x];
        for(auto i = curList.begin(); i!=curList.end(); i++){
            if(visited[*i] == INT_MAX){
                visited[*i] = visited[x] + 6;
                q.push(*i);
            }
          
        }
    }
    
  
    for(int i=1; i<=n; i++){
        if(i==s) continue;
        if(visited[i] == INT_MAX) {
            output.push_back(-1); continue;
        }
        output.push_back(visited[i]);
    }
    
    return output;

}