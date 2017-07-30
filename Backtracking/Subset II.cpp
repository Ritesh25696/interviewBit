Given a collection of integers that might contain duplicates, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
Example :
If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]

***********************************************************************************************************************************************

void subsethelper(vector<vector<int>> &ans, vector<int> &row , vector<int> &A , int i){
    if(i == A.size()){
        ans.push_back(row);
        return;
    }
    row.push_back(A[i]);
    subsethelper(ans , row , A ,i+1);
    row.pop_back();
    subsethelper(ans , row , A ,i+1);
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
  vector<vector<int>> ans;
  vector<int> row;
  sort(A.begin(),A.end());
  subsethelper(ans , row , A , 0);
  sort(ans.begin() , ans.end());
  ans.erase(unique(ans.begin(),ans.end()),ans.end());
  return ans;
  
}
