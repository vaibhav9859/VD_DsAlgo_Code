#include <vector>
#include <queue>
vector<int> kLargest(int input[], int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
	vector<int> output;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for(int i=0; i<k; i++) min_heap.push(input[i]);
    
    for(int i=k; i<n; i++){
        if(min_heap.top() < input[i]){
            min_heap.pop();
            min_heap.push(input[i]);
        }
    }
    while(!min_heap.empty()){
        output.push_back(min_heap.top());
        min_heap.pop();
    }
    return output;
}
