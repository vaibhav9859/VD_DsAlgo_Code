vector <int> bfs(vector<int> g[], int N) {

    vector<int> v(N, -1); vector<int> ans;
    queue<int> q; q.push(0);
    while(!q.empty()){
        ans.push_back(q.front());
        int x= q.front(); 
        // cout<<x<<" ";
        q.pop();
        
        for(int j=0; j<g[x].size(); j++){
            if(v[ g[x][j] ] == -1) {v[ g[x][j] ] = 1;  q.push(g[x][j]);}
        }
    }
    return ans;
}