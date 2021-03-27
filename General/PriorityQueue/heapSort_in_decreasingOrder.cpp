using namespace std;
void addInHeap(int *arr, int index){
    while(index > 0){
        int parentIndex = (index - 1)/2;

        if(arr[parentIndex] > arr[index]){
            swap(arr[parentIndex], arr[index]);
            index = parentIndex;
        }
        else break;        
    }

}

void downHeapify(int *arr, int size){
    
    int leftIndex, rightIndex, parentIndex=0, minIndex=0;
    leftIndex = 2*parentIndex + 1; rightIndex = 2*parentIndex + 2;
    
    while(leftIndex < size){
        if(arr[leftIndex] < arr[parentIndex]) minIndex = leftIndex;
        else minIndex = parentIndex;
        
        if(rightIndex < size and arr[rightIndex] < arr[minIndex]){
            minIndex = rightIndex;
        }
        if(minIndex == parentIndex) break;
        swap(arr[parentIndex], arr[minIndex]);
        parentIndex = minIndex;
        leftIndex = 2*parentIndex + 1; rightIndex = 2*parentIndex + 2;
    }
}

void heapSort(int arr[], int n) {
    for(int i=1; i<n; i++){
        addInHeap(arr, i);
    }
    
    for(int i=n-1; i>0; i--){
        swap(arr[0], arr[i]);
        downHeapify(arr, i);
    }
    
}
