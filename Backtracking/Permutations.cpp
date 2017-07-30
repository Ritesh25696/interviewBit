Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]
 NOTE
No two entries in the permutation sequence should be the same.
For the purpose of this problem, assume that all the numbers in the collection are unique.

***********************************************************************************************************************

void swap(int &a,int &b){
    int c=a;
    a=b;
    b=c;
}
void permutations(vector<int> &A,vector< vector<int> > &v,int l){
  if(l==A.size()-1){
    v.push_back(A);
    return;
  }
  for(int i=l;i<A.size();i++){
    swap(A[l],A[i]);
    permutations(A,v,l+1);
    swap(A[l],A[i]);
  }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int> > v;
    permutations(A,v,0);
    sort(v.begin(),v.end());
    return v;
}
