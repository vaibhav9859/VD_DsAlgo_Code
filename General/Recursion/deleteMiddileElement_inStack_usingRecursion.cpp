#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

void deleteMiddle(stack<int> &s, int index){
    if(index == 1){
        s.pop(); return;
    }
    int temp = s.top(); s.pop();
    deleteMiddle(s, index-1);
    s.push(temp);
}


int main(){
    int n; cin>>n;
    stack<int> s;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        s.push(x);
    }
    
    if(n%2) deleteMiddle(s, n/2 +1);
    else deleteMiddle(s, n/2);

    vector<int> v;
    for(int i=0; !s.empty(); i++){
        v.push_back(s.top());
        s.pop();
    }
    reverse(v.begin(), v.end());
    for(int i=0; i< v.size(); i++){  
        cout<<v[i]<<" ";
    }
    return 0;
}
