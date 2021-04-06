
int countMinStepsToOne(int n)
{
    int* arr = new int[n+1];
   	arr[0] = arr[1] = 0;
    
    for(int i=2; i<n+1; i++){
        int x, y, z; x=y=z=INT_MAX;
        if(i-1 > 0) x = arr[i-1];
        if(!(i%2))  y = arr[i/2];
        if(!(i%3)) z = arr[i/3];
        
        arr[i] = 1 + min(x, min(y,z));
    }
    return arr[n];
}
