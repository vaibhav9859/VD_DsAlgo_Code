#include<queue>
#include<vector>
vector<int> kSmallest(int arr[], int n, int k) {
	vector<int> output;
    priority_queue<int> max_heap;
    for(int i=0; i<k; i++){
        max_heap.push(arr[i]);
    }
    
    for(int i=k; i<n; i++){
        if(max_heap.top() > arr[i]){
            max_heap.pop();
            max_heap.push(arr[i]);
        }
    }
    while(!max_heap.empty()){
        output.push_back(max_heap.top());
        max_heap.pop();
    }
    return output;
}
