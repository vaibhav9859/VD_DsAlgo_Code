/*
First line in input is size of stack, And second line have elements which will be pushed inside stack on execution

SAMPLE INPUT: 
10
1 2 3 4 5 6 7 8 9 0
*/



#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

void pushAtEnd(stack<int> &s, int element){
    if(s.empty()){
        s.push(element); return;
    }
    int elementOut = s.top(); s.pop();
    pushAtEnd(s, element);
    s.push(elementOut);
}
void reverseStack(stack<int> &s, int i=0){
    if(s.empty()) return;
    int element = s.top(); s.pop();
    reverseStack(s);
    pushAtEnd(s, element);
    
}
int main(){
    stack<int> s; int size; cin>>size; vector<int> v;
    for(int i=0; i<size; i++){
        int x; cin>>x; s.push(x);
        v.push_back(x);
    }
    reverse(v.begin(), v.end());
    cout<<"Original Stack: ";
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";

    cout<<endl;
    reverseStack(s);
    cout<<"Reversed Stack: ";
    for(int i=0; i<size; i++){
        if(s.empty()) break;
        cout<<s.top()<<" ";

        s.pop();
    }


    return 0;
}
