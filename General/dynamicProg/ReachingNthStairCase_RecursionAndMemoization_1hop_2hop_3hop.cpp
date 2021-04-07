long stairCaseHelper(int n, long* memoize){
	if(n<0) return 0;
	if(n<=2) return n;
    if(n==3) return 4;
    if(memoize[n] != -1) return memoize[n];
    return memoize[n] = stairCaseHelper(n-1, memoize) + stairCaseHelper(n-2, memoize) + stairCaseHelper(n-3, memoize);    
}
long staircase(int n)
{
    long *memoize = new long[n+1];
    
    for(int i=0; i<n+1; i++){
        memoize[i] = -1;
    }
    stairCaseHelper(n, memoize);
}
