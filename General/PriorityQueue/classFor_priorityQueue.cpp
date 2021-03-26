#include <vector>
#include <algorithm> 

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        int ans = pq[0];
        swap(pq[0], pq[pq.size()-1]);
        pq.pop_back();
        int i=0; int firstMin, secondMin;
        while(2*i+1 < pq.size()){
            
            if(pq[i] < pq[2*i+1] and 2*i+2 < pq.size() and pq[i] < pq[2*i+2]) break;
            if(pq[i] < pq[2*i+1] and 2*i+2 >=pq.size()) break;
            
            if(pq[i] < pq[2*i+1] ) firstMin = i;
            else firstMin = 2*i+1;
            
            if(2*i+2 <= getSize()-1 and pq[firstMin] > pq[2*i+2]){
                secondMin = 2*i+2;
            }
            else secondMin = firstMin;
            
            swap(pq[i], pq[secondMin]);
        }
        
        return ans;
    }
};
