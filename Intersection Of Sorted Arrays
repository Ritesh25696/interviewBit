Find the intersection of two sorted arrays.
OR in other words,
Given 2 sorted arrays, find all the elements which occur in both the arrays.

Example :

Input : 
    A : [1 2 3 3 4 5 6]
    B : [3 3 5]

Output : [3 3 5]

Input : 
    A : [1 2 3 3 4 5 6]
    B : [3 5]

Output : [3 5]
 
 ******************************************************************************************************************************************************
 
 int i=0 , j=0;
      vector<int> res;
      if(A.size() == 0 || B.size() ==0)return res;
      while(i<A.size() && j<B.size()){
          if(A[i] == B[j]){
              res.push_back(A[i]);
              i++;j++;
          }
          else if(A[i] < B[j])i++;
          else j++;
      }
      return res;
}
