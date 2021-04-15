#include<map>
#include<vector>
void intersection(int *arr1, int *arr2, int n, int m) 
{
	map<int, int> m1, m2;
    vector<int> output;
    for(int i=0; i<n; i++){
        m1[arr1[i]]++;
    }
    for(int i=0; i<m; i++){
        m2[arr2[i]]++;
    }
    
    for(auto i=m1.begin(); i != m1.end(); i++){
        if(min(i->second, m2[i->first]) > 0){
            for(int k=0; k < min(i->second, m2[i->first]); k++){
				output.push_back(i->first);
            }
           
        }
    }
    sort(output.begin(), output.end());
    for(int i=0; i < output.size(); i++){
        cout<<output[i]<<" ";
    }
}
