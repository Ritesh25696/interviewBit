Given two sorted integer arrays A and B, merge B into A as one sorted array.

 Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.
TIP: C users, please malloc the result into a new array and return the result. 
If the number of elements initialized in A and B are m and n respectively, the resulting size of array A after your code is executed should be m + n

Example :

Input : 
         A : [1 5 8]
         B : [6 9]

Modified A : [1 5 6 8 9]

*******************************************************************************************************************

void Solution::merge(vector<int> &A, vector<int> &B) {
 int n = A.size() , m = B.size() , j=0 , i=0;
 while(i<n && j<m){
     if(A[i] <= B[j]){
         A.push_back(A[i]);
         i++;
     }
     else{
         A.push_back(B[j]);
         j++;
     }
 }
 while(i<n){
     A.push_back(A[i]);
     i++;
 }
 while(j<B.size()){
     A.push_back(B[j]);
     j++;
 }
 A.erase(A.begin(),A.begin()+n);
}
