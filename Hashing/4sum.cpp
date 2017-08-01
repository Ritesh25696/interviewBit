Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

 Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
Example : 
Given array S = {1 0 -1 0 -2 2}, and target = 0
A solution set is:

    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    (-1,  0, 0, 1)
Also make sure that the solution set is lexicographically sorted.
Solution[i] < Solution[j] iff Solution[i][0] < Solution[j][0] OR (Solution[i][0] == Solution[j][0] AND ... Solution[i][k] < Solution[j][k])

****************************************************************************************************************************************************

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
   sort(A.begin() , A.end());
   vector<vector<int>> res;
   unordered_map<int,vector<int>> mymap;
   if(A.size() < 4)return res;
   for(int i=3 ; i<A.size() ; i++){
       mymap[A[i]].push_back(i);
   }
   
   for(int i=0 ; i<A.size()-3 ; i++){
       for(int j=i+1 ; j<A.size()-2 ; j++){
           for(int k=j+1 ; k<A.size()-1 ; k++){
               int p = B - A[i]-A[k]-A[j];
               if(mymap.find(p) != mymap.end()){
                   for(int l=0 ; l<mymap[p].size() ; l++){
                       if(mymap[p][l] > k ){
                           vector<int> r;
                           r.push_back(A[i]);r.push_back(A[j]);r.push_back(A[k]);
                           r.push_back(A[mymap[p][l]]);
                           res.push_back(r);
                       }
                   }
               }
           }
       }
   }
   sort(res.begin() , res.end());
   res.erase(unique(res.begin(),res.end()),res.end());
   return res;
}
