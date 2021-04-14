class Solution{
    public:
        int lcs(int x, int y, string s1, string s2){
            int **dp;
            dp  = new int*[x+1];
            
            for(int i=0; i< x+1; i++){
                dp[i] = new int[y+1];
            }
            
            
            int ans = lcsHelper(x, y, s1, s2, dp);
            
            for(int row = 0; row < x+1; row++){
                for(int col = 0; col < y+1; col++){
                    cout<< dp[row][col]<<" ";    
                }
                cout<<endl;
            }
            
            cout<<endl;
            return ans;
        }
        
        int lcsHelper(int x, int y, string s1, string s2, int**dp){
            // if(x == 0 or y == 0) return 0;
           for(int row = 0; row< x+1; row++){
                for(int col = 0; col < y+1; col++){
                    if(row ==0 or col==0){
                        dp[row][col] = 0; 
                    } 
                }
            }
           
           for(int row = 1; row < x+1; row++){
               for(int col = 1; col < y+1; col++){
            // if(s1[x-1] == s2[y-1]){
            //     return dp[x-1][y-1] = 1 + dp[x-1][y-1]  (x-1, y-1, s1, s2, dp);
            // }
                  if(s1[row-1] == s2[col-1]){
                      dp[row][col] = 1 + dp[row-1][col-1];
                  }
                  else{
                    //   return dp[x-1][y-1] = max(lcsHelper(x-1, y, s1, s2, dp), lcsHelper(x, y-1, s1, s2, dp));
          
                      dp[row][col] = max(dp[row-1][col], dp[row][col-1]);
                  }
               }
           }
        
            return dp[x][y];
            
            
        }
};
