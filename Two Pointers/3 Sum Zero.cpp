Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets. For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
(-1, 0, 1)
(-1, -1, 2) 

************************************************************************************************************

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    
     sort(A.begin() , A.end());
     vector<vector<int>> result;
     if(A.size() < 3){return result;}
     vector<int> res;
     for(int i=0 ; i<A.size()-2 ; i++){
         int l=i+1 , r = A.size()-1;
         while(l<r){

             if(A[i]+A[l]+A[r] == 0){
                 res.push_back(A[i]);
                 res.push_back(A[l]);
                 res.push_back(A[r]);
                 result.push_back(res);
                 res.clear();
                 l++;
                 r--;
             }
             else if(A[i]+A[l]+A[r]<0){
                 l++;
             }
             else{
                 r--;
             }

         }
     }
     sort(result.begin(), result.end());
     result.erase(unique(result.begin(), result.end()), result.end());
     return result;

}
