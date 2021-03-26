#include <vector>
class PriorityQueue {
    // Declare the data members here
	vector<int> pq;
   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        pq.push_back(element);
        int childIndex = getSize() - 1;
        int parentIndex;
        while(childIndex != 0){
        	parentIndex = (childIndex - 1)/2;
            if(pq[parentIndex] < pq[childIndex]) swap(pq[parentIndex], pq[childIndex]);
            else break;
            
            childIndex = parentIndex;
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if(!isEmpty()) return pq[0];
        return 0;
    }

    int removeMax() {
        // Implement the removeMax() function here
    	int ans = pq[0];
        swap(pq[0], pq[getSize()-1]); pq.pop_back();
        int maxIndex=0, leftChildIndex = 2*maxIndex + 1, rightChildIndex = 2*maxIndex + 2;
        int newMaxIndex=0;
        //down-heapify
        while(leftChildIndex < getSize()){
            if(pq[leftChildIndex] > pq[maxIndex]) newMaxIndex = leftChildIndex;
            if(rightChildIndex < getSize() and pq[rightChildIndex] > pq[maxIndex]) newMaxIndex = rightChildIndex;
            if(newMaxIndex == maxIndex) break;
            swap(pq[newMaxIndex], pq[maxIndex]);
            maxIndex = newMaxIndex;
            leftChildIndex = 2*maxIndex + 1;
            rightChildIndex = 2*maxIndex + 2;
        }
        
        return ans;
        
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return (pq.size() == 0);
    }
};
