class Solution {
public:
    int jump(vector<int>& A) {
        int n=A.size();
      
        int c=0,ma=0,cm=0;
   for(int i=0;i<n-1;i++)
   {
        ma=max(i+A[i],ma);
       if(i==cm)
       {
           c++;
           cm=ma;
       }
       
    
    }
        
    return c;
    }
};
