#include<queue>
#include<vector>

class trip{
  public:
    int value;
    int vi;
    int li;
};
struct Comparevalue {
    bool operator()(trip const & t1, trip const & t2) {
        // return "true" if "p1" is ordered before "p2", for example:
        return t1.value > t2.value;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return the output.
     * Taking input and printing output is handled automatically.
     */
    vector<int> v;
    
    priority_queue<trip,vector<trip>,Comparevalue> pq;
	for(int i = 0;i<input.size();i++){
        trip a;
        a.value = input[i]->at(0);
        a.vi = i;
        a.li = 0;
        pq.push(a);
    }
    while(pq.size()!=0){
        trip z = pq.top();
        v.push_back(z.value);
        pq.pop();
        if((z.li+1)<input[z.vi]->size()){
            trip n;
            n.value = input[z.vi]->at(z.li + 1);
            n.vi = z.vi;
            n.li = z.li+1;
            pq.push(n);
        }
    }
	return v;
}
