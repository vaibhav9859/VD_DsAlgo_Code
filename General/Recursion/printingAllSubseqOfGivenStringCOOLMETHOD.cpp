#include<iostream>
#include<string>

using namespace std;

void printSubseq(string input, string output){
    if(input.size() == 0){
        cout<<output<<endl;
        return;
    }
    
    printSubseq(input.substr(1), output);
    printSubseq(input.substr(1), output + input[0]);
}

int main(){
    printSubseq("abc", "");
    return 0;
}
