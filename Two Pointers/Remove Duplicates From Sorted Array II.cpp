Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

Note that even though we want you to return the new length, make sure to change the original array as well in place

For example,
Given input array A = [1,1,1,2],

Your function should return length = 3, and A is now [1,1,2].

**************************************************************************************************************

int Solution::removeDuplicates(vector<int> &A) {
  if(A.size() < 2 )return A.size();
 int ins = 2;
 for(int i=2 ; i<A.size() ; i++){
    if(A[i] == A[i-1] && A[i] != A[ins-2]){
        A[ins] = A[i];
        ins++;
    }
    else if(A[i] > A[i-1]){
        A[ins] = A[i];
        ins++;
    }
 }
 A.erase(A.begin()+ins, A.begin()+A.size());
 return A.size();
}
