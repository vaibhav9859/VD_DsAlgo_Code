#include <iostream>
#include<vector>
#include <cmath>
using namespace std;

int subSeq(string s, string* output, int i=0){
    if(i==s.size()){
        output[0] = "";  return 1;
    }
    int curSize = subSeq(s, output, i+1);
    int tempSize = curSize;
    for(int j=0, k = curSize; j<curSize; j++, k++){
        output[k] = ( s[i] + output[j] );    
        tempSize++;
    }
    return tempSize;
}


int main() {
	// your code goes here
	string s; cin>>s;
	int sizeOfOutput = pow(2, s.size());
	string* output = new string[sizeOfOutput];
	int size = subSeq(s, output);
	
	for(int i=0; i<size; i++){
	    cout<<output[i]<<endl;
	}
	return 0;
}
