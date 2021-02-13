#include <iostream>
using namespace std;

void merge(int *input, int size, int start, int mid, int end){
    int arr[end-start+5];
    int i, j; int it;
    
   for( i=start, j=mid+1, it =0; i<=mid and j<=end; it++ ){
        if(input[i]<= input[j]) {
           (arr[it] = input[i]); i++; 
        }
        else{
            (arr[it] = input[j]); j++; 
        }
    }
    while(i<=mid){
        (arr[it] = input[i]); i++; it++;
    }
    while(j<=end){
       (arr[it] = input[j]); j++; it++;
    }
    
    for(int i=start, k=0; i<=end; i++, k++){
        input[i] = arr[k];
    }
}

void mergeSortHelper(int *input, int size, int start, int end){
    if(start>=end) return;
    int mid = start + (end - start)/2;
    mergeSortHelper(input, size, start, mid);
    mergeSortHelper(input, size, mid+1, end);
    merge(input, size, start, mid, end);
}

int main() {
    int size; cin>>size;
    int input[size];
    for(int i=0; i<size; i++) cin>>input[i];
    mergeSortHelper(input, size, 0, size-1);

    for(int i=0; i<size; i++) cout<<input[i]<<" ";
}
