#include <iostream>
using namespace std;
void swap(int & x, int &y){
    int temp =x;
     x = y; y = temp;
}
int partition(int *input, int start, int end ){
    int pivot = input[start]; int count=0;
    for(int i=start+1; i<=end; i++){
        if(pivot > input[i]) count++;
    }
    swap(input[start], input[start + count]);
    for(int i=start, j=end; i<start + count and j>start + count; ){
        while(input[i] < pivot and i<start + count){
            i++; 
        }
        while( i<start + count and input[j] >= pivot and j>start + count){
            j--; continue;
        }
        if(i<start + count and j>start + count){
            swap(input[i], input[j]);
            i++; j--;
        }
    }

    return start + count;
}


void quickSortHelper(int *input, int start, int end){
    
    if(start>=end) return;
	int index = partition(input, start, end);
    quickSortHelper(input, start, index-1);
    quickSortHelper(input, index+1, end);
}

int main() {
    int size; cin>>size;
    int input[size];
    for(int i=0; i<size; i++) cin>>input[i];
    quickSortHelper(input, 0, size-1);

    for(int i=0; i<size; i++) cout<<input[i]<<" ";
}
