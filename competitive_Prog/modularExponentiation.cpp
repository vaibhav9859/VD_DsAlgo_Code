int power(long long int base, long long int expn, long long int mod){
    int result = 1;
    
    while(expn > 0){
        if(expn % 2 ){
            result = (result%mod * base%mod) % mod;
            expn -= 1;
        }
        else{
            base = (base%mod * base%mod) % mod;
            expn /= 2;
        }
    }
    
    return result;
}
