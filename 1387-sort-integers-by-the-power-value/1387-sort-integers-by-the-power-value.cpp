class Solution {
public:
    unordered_map<int,int>fact ;
    
    int KthCounter(int n)
    {
        if( fact[n] || n == 1 )
            return fact[n];
        
        if(n&1)//n is odd
        {
            fact[n]=1+KthCounter(3*n+1);
        }
        else
            fact[n]=1+KthCounter(n/2);
            
        return fact[n];
    }
    
    int getKth(int lo, int hi, int k) {
        
        vector<pair<int,int>>res ;
        
        for(int i=lo;i<=hi;i++)
        {
            res.push_back( {KthCounter(i),i} ) ;
        }
        sort(res.begin(),res.end());
        
        return res[k-1].second ;
    }

};