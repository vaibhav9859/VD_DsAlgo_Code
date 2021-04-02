#include<unordered_map>
#include<climits>
int highestFrequency(int arr[], int n) {
    if(n==0) return 0;
    unordered_map<int, pair<int, int>> myMap;
    
    for(int i=0; i<n; i++){
        if(myMap[arr[i]].second == 0) myMap[arr[i]].first = i;
        (myMap[arr[i]].second)++;
    }
    
	int index=INT_MAX, ans=INT_MIN;
    for(auto i=myMap.begin(); i!=myMap.end(); i++){
        if(ans == (i->second).second){
        	if(index > (i->second).first) index = (i->second).first;   
        }
        else if(ans < (i->second).second ) {
            ans = (i->second).second;
            index = (i->second).first;
        }
    }
	return arr[index];
}
