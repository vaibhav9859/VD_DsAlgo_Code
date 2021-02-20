#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

void insert(stack<int> &s, int temp){
    if(s.empty() or s.top()<=temp){
        s.push(temp); return;
    }
    
    int anotherTemp = s.top();
    s.pop();
    insert(s, temp);
    s.push(anotherTemp);
}

void sort(stack<int> &s){
    if(s.size() == 1) return;
    int temp = s.top();
    s.pop();
    sort(s);
    insert(s, temp);
}

int main(){
    int n; cin>>n;
    stack<int> s;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        s.push(x);
    }
    sort(s);

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
