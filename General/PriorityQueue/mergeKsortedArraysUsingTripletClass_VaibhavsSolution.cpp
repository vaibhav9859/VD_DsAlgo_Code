#include<vector>
#include<queue>
class triplet{
	public:
        int value;
        int rowIndex;
        int colIndex;
};

class compareFunction{
	public:
        bool operator()(triplet const & arg1, triplet const & arg2){
            return arg1.value <= arg2.value;
        }
};


vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
	vector<int> output;
	priority_queue<triplet, vector<triplet>, compareFunction> min_heap;    
    
    for(int i=0; i < input.size(); i++){
        triplet curTrip;
        // what is input? It is vector of "pointers" to vectors
        curTrip.value = input[i]->at(0);
        curTrip.rowIndex = i;
        curTrip.colIndex = 0;
        min_heap.push(curTrip);
    }
    
    // output.push_back(min_heap.top().value);
    while(!min_heap.empty()){
        triplet temp = min_heap.top();
        output.push_back(temp.value);
        min_heap.pop();
        if(temp.colIndex + 1 < input[temp.rowIndex]->size()){
            triplet newTripToBePushed;
            newTripToBePushed.value = input[temp.rowIndex]->at(temp.colIndex + 1);
            newTripToBePushed.rowIndex = temp.rowIndex;
            newTripToBePushed.colIndex = temp.colIndex + 1;

            min_heap.push(newTripToBePushed);
        }        
    }

    return output;
}
