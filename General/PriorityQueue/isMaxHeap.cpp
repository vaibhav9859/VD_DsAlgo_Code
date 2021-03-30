bool isMaxHeap(int arr[], int n, int parentIndex = 0) {
    if(parentIndex >= n) return true;
    int leftIndex = parentIndex*2 + 1;
    int rightIndex = parentIndex*2 + 2;
    
    if(leftIndex < n and arr[leftIndex] > arr[parentIndex])
        return false;
    if(rightIndex < n and arr[rightIndex] > arr[parentIndex])
		return false;
    
    return true and isMaxHeap(arr, n, leftIndex) and isMaxHeap(arr, n , rightIndex);
}
