Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based. 
Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.

If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.

Input: [2, 7, 11, 15], target=9
Output: index1 = 1, index2 = 2

*********************************************************************************************************************************************************************

vector<int> Solution::twoSum(const vector<int> &A, int B) {
vector<int> res(2 , INT_MAX);
 bool done = false;
 if(A.size() < 2){res.clear();return res;}
 unordered_map<int,int> map;
 for(int i=0 ; i<A.size() ; i++){
    if(map.find(A[i]) != map.end()){
        if(B == 2*A[i] && done == false){
            res[0] = map[A[i]];
            res[1] = i+1;
            done = true;
        }
    }
    else{
        map[A[i]] = i+1;
    }
 }
 for(int i=0 ; i<A.size() ; i++){

     int k = B-A[i];
     if(map.find(k) != map.end()){
         if(map[k]<res[1] && i+1<map[k]){
             res[0] = i+1;
             res[1] = map[k];
         }
         else if(map[k] == res[1] && i+1 <res[0] ){
             res[0] = i+1;
             res[1] = map[k];
         }
     }
 }
 if(res[0] == INT_MAX){
    res.clear();
    return res;
 }
 return res;
}
