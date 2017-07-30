Given a set of distinct integers, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]
*************************************************************************************************************************************************

void subsetHelper(int i, vector<int> & subset, vector<vector<int>> & ans, vector<int> & A){
    if(i==A.size()){
        ans.push_back(subset);
        return;
    }
    subsetHelper(i+1, subset, ans, A);
    subset.push_back(A[i]);
    subsetHelper(i+1, subset, ans, A);
    subset.pop_back();
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector< vector<int> > ans;
    vector<int> subset;
    sort(A.begin(), A.end());
    subsetHelper(0, subset, ans, A);
    sort(ans.begin(), ans.end());
    return ans;
}
